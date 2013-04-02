#include <avr/io.h>

#include "config.h"
#include "io.h"
#include "netvar/netvar.h"
#include "netvar/netvar_io.h"

// the inverted parameter is used to normalize all inputs
// before they are stored in the state parameter and passed to the changed event.
// The normalized values are:
// Taster            1 = pressed, 0 = released
// Türkontakt        1 = on, 0 = off

static struct t_pin_parameter {
	uint8_t state;
	int8_t debounce_count;
	uint8_t inverted;
	volatile uint8_t *pin;
	uint8_t bit;
} pin_matrix[] = {
	{ 0, 0, 1, (&(I_PIN_0)), I_BV_0},
	{ 0, 0, 0, (&(I_PIN_1)), I_BV_1}
};


#define LED 0

static void lamp_out(void *num, uint8_t val) {
	uint8_t i = (uint8_t) (uint16_t) num;
	switch (i) {
		case LED:
			if (val) {
				PORTC |= R_LED;
				PORTC &= ~(G_LED);
			} else {
				PORTC |= G_LED;
				PORTC &= ~(R_LED);
			}
			break;
	}
}

#define NV_IDX_LAMP_CONTROLLER_KUECHE 0x0102

void lamp_out_init() {
	new_netvar_output_8(NV_IDX_LAMP_CONTROLLER_KUECHE, 0x3f, lamp_out, (void *) LED);
}

static netvar_desc *out_netvars[NUM_INPUTS];

void switch_netvars_init() {
	out_netvars[0] = netvar_register(0x0102, 0x2f, 1); // Taster Küche
	out_netvars[1] = netvar_register(0x0008, 0x00, 1); // Alarmbutton
}

static void input_changed_event(uint8_t num, uint8_t val) {
	if (num == 1) {
		if (val)
			PORTD |= _BV(PD5) | _BV(PD6) | _BV(PD7);
		else
			PORTD &= ~(_BV(PD5) | _BV(PD6) | _BV(PD7));
	}
	netvar_write(out_netvars[num], &val);
}

#define DEBOUNCE_CYCLES 2

/*
*  debounce monitored inputs, invert them if wanted, and check for changes
*  on change: call input_changed_event
*/

void switch_handler() {
	uint8_t i;
	for (i = 0; i < NUM_INPUTS; i++) {
		if ((*pin_matrix[i].pin) & pin_matrix[i].bit) {
			pin_matrix[i].debounce_count++;
			if (pin_matrix[i].debounce_count > DEBOUNCE_CYCLES) {
				pin_matrix[i].debounce_count = DEBOUNCE_CYCLES;
				if (pin_matrix[i].state == pin_matrix[i].inverted) {
					pin_matrix[i].state = pin_matrix[i].inverted ^ 1;
					input_changed_event(i, pin_matrix[i].state);
				}
			}
		} else {
			pin_matrix[i].debounce_count--;
			if (pin_matrix[i].debounce_count < 0) {
				pin_matrix[i].debounce_count = 0;
				if (pin_matrix[i].state == (pin_matrix[i].inverted ^ 1)) {
					pin_matrix[i].state = pin_matrix[i].inverted;
					input_changed_event(i, pin_matrix[i].state);
				}
			}
		}
	}
}
