--------------------------------------------------------------------------------
-- Copyright (c) 1995-2007 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 9.2.04i
--  \   \         Application : xaw2vhdl
--  /   /         Filename : takt.vhd
-- /___/   /\     Timestamp : 05/26/2009 05:03:34
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: xaw2vhdl-intstyle D:/Borg Ventilator sender/takt.xaw -st takt.vhd
--Design Name: takt
--Device: xc3s200-5ft256
--
-- Module takt
-- Generated by Xilinx Architecture Wizard
-- Written for synthesis tool: XST
-- Period Jitter (unit interval) for block DCM_INST = 0.14 UI
-- Period Jitter (Peak-to-Peak) for block DCM_INST = 0.70 ns

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity takt is
   port ( CLKIN_IN        : in    std_logic; 
          RST_IN          : in    std_logic; 
          CLKIN_IBUFG_OUT : out   std_logic; 
          CLK0_OUT        : out   std_logic);
end takt;

architecture BEHAVIORAL of takt is
   signal CLKFB_IN        : std_logic;
   signal CLKIN_IBUFG     : std_logic;
   signal CLK0_BUF        : std_logic;
   signal GND_BIT         : std_logic;
begin
   GND_BIT <= '0';
   CLKIN_IBUFG_OUT <= CLKIN_IBUFG;
   CLK0_OUT <= CLKFB_IN;
   CLKIN_IBUFG_INST : IBUFG
      port map (I=>CLKIN_IN,
                O=>CLKIN_IBUFG);
   
   CLK0_BUFG_INST : BUFG
      port map (I=>CLK0_BUF,
                O=>CLKFB_IN);
   
   DCM_INST : DCM
   generic map( CLK_FEEDBACK => "1X",
            CLKDV_DIVIDE => 2.0,
            CLKFX_DIVIDE => 1,
            CLKFX_MULTIPLY => 4,
            CLKIN_DIVIDE_BY_2 => FALSE,
            CLKIN_PERIOD => 20.000,
            CLKOUT_PHASE_SHIFT => "NONE",
            DESKEW_ADJUST => "SYSTEM_SYNCHRONOUS",
            DFS_FREQUENCY_MODE => "LOW",
            DLL_FREQUENCY_MODE => "LOW",
            DUTY_CYCLE_CORRECTION => TRUE,
            FACTORY_JF => x"8080",
            PHASE_SHIFT => 0,
            STARTUP_WAIT => FALSE)
      port map (CLKFB=>CLKFB_IN,
                CLKIN=>CLKIN_IBUFG,
                DSSEN=>GND_BIT,
                PSCLK=>GND_BIT,
                PSEN=>GND_BIT,
                PSINCDEC=>GND_BIT,
                RST=>RST_IN,
                CLKDV=>open,
                CLKFX=>open,
                CLKFX180=>open,
                CLK0=>CLK0_BUF,
                CLK2X=>open,
                CLK2X180=>open,
                CLK90=>open,
                CLK180=>open,
                CLK270=>open,
                LOCKED=>open,
                PSDONE=>open,
                STATUS=>open);
   
end BEHAVIORAL;


