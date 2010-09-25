// Copyright (C) 2008, 2009 by Sirrix AG security technologies
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

/**
 * @file        KeyronaManager.hxx
 * @brief       The management functions...
 * @version     $Revision: 792 $
 * @date        Last modification at $Date: 2009-08-05 15:03:56 +0200 (Wed, 05 Aug 2009) $ by $Author: goericke $
 */


#ifndef _KEYRONAMANAGER_HXX
#define	_KEYRONAMANAGER_HXX

#include <KeyronaConfigfile.hxx>
#include <KeyronaLogin.hxx>
#include <KeyronaStorage.hxx>
#include <KeyronaSubject.hxx>
#include <KeyronaGroup.hxx>
#include <KeyronaESD.hxx>
#include <KeyronaSearch.hxx>
#include <KeyronaVolume.hxx>

// Volume Types
enum myKeyronaPlatformType
{
    PLATFORMTYPE_BEGIN = 0,
    PLATFORMTYPE_PCR0,
    PLATFORMTYPE_PCR1,
    PLATFORMTYPE_PCR2,
    PLATFORMTYPE_PCR3,
    PLATFORMTYPE_PCR4,
    PLATFORMTYPE_PCR5,
    PLATFORMTYPE_PCR6,
    PLATFORMTYPE_PCR7,
    PLATFORMTYPE_PCR8,
    PLATFORMTYPE_PCR9,
    PLATFORMTYPE_PCR10,
    PLATFORMTYPE_PCR11,
    PLATFORMTYPE_PCR12,
    PLATFORMTYPE_PCR13,
    PLATFORMTYPE_PCR14,
    PLATFORMTYPE_PCR15,
    PLATFORMTYPE_PCR16,
    PLATFORMTYPE_PCR17,
    PLATFORMTYPE_PCR18,
    PLATFORMTYPE_PCR19,
    PLATFORMTYPE_PCR20,
    PLATFORMTYPE_PCR21,
    PLATFORMTYPE_PCR22,
    PLATFORMTYPE_PCR23,
    PLATFORMTYPE_END
};

const std::string KeyronaPlatformType_PCR0    = "PCR0";
const std::string KeyronaPlatformType_PCR1    = "PCR1";
const std::string KeyronaPlatformType_PCR2    = "PCR2";
const std::string KeyronaPlatformType_PCR3    = "PCR3";
const std::string KeyronaPlatformType_PCR4    = "PCR4";
const std::string KeyronaPlatformType_PCR5    = "PCR5";
const std::string KeyronaPlatformType_PCR6    = "PCR6";
const std::string KeyronaPlatformType_PCR7    = "PCR7";
const std::string KeyronaPlatformType_PCR8    = "PCR8";
const std::string KeyronaPlatformType_PCR9    = "PCR9";
const std::string KeyronaPlatformType_PCR10    = "PCR10";
const std::string KeyronaPlatformType_PCR11    = "PCR11";
const std::string KeyronaPlatformType_PCR12    = "PCR12";
const std::string KeyronaPlatformType_PCR13    = "PCR13";
const std::string KeyronaPlatformType_PCR14    = "PCR14";
const std::string KeyronaPlatformType_PCR15    = "PCR15";
const std::string KeyronaPlatformType_PCR16    = "PCR16";
const std::string KeyronaPlatformType_PCR17   = "PCR17";
const std::string KeyronaPlatformType_PCR18   = "PCR18";
const std::string KeyronaPlatformType_PCR19   = "PCR19";
const std::string KeyronaPlatformType_PCR20   = "PCR20";
const std::string KeyronaPlatformType_PCR21   = "PCR21";
const std::string KeyronaPlatformType_PCR22   = "PCR22";
const std::string KeyronaPlatformType_PCR23   = "PCR23";


/*!
  *  @brief adds a group to a volume in the database
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */   
void KeyronaAddGroupToVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief adds a secret sharing sheme to a volume in the database
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  *  @param &mySSSStorage, KeyronaStorage, points to the current secret sharing scheme database
  */
void KeyronaAddSSSToVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage, KeyronaStorage &mySSSStorage);

/*!
  *  @brief adds a subject to a group in the database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */   
void KeyronaAddSubjectToGroup(KeyronaStorage &myGroupStorage, KeyronaStorage &mySubjectStorage);

/*!
  *  @brief adds a subject to a volume in the database
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */ 
void KeyronaAddSubjectToVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief changes the path, where the volume can be found
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaAttachVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief creates a new admin
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  */
void KeyronaCreateAdmin(KeyronaStorage &mySubjectStorage);

/*!
  *  @brief creates a new group
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaCreateGroup(KeyronaStorage &myGroupStorage, KeyronaStorage &mySubjectStorage);

/*!
  *  @brief creates a new platform
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  */
void KeyronaCreatePlatform(KeyronaStorage &mySubjectStorage);

/*!
  *  @brief creates a new token
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  */
void KeyronaCreateToken(KeyronaStorage &mySubjectStorage);

/*!
  *  @brief creates a new user
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  */
void KeyronaCreateUser(KeyronaStorage &mySubjectStorage);

void KeyronaCreateESD			 ( KeyronaStorage &myESDStorage );



/*!
  *  @brief deletes a user from a volume
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaCreateVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief deletes an admin in the database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaDeleteAdmin(KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief deletes a group from a volume
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaDeleteGroupFromVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief deletes a group in the database
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaDeleteGroup(KeyronaStorage &myGroupStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myVolumeStorage);

/*!
  *  @brief deletes a platform from the database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  */
void KeyronaDeletePlatform(KeyronaStorage &mySubjectStorage);

/*!
  *  @brief deletes a secret sharing scheme from a volume
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  *  @param &mySSSStorage, KeyronaStorage, points to the current secret sharing scheme database
  */
void KeyronaDeleteSSSFromVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage, KeyronaStorage &mySSSStorage);

/*!
  *  @brief deletes a subject from a group
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaDeleteSubjectFromGroup(KeyronaStorage &myGroupStorage, KeyronaStorage &mySubjectStorage);

/*!
  *  @brief deletes a subject from a volume
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaDeleteSubjectFromVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief deletes a token in the database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  */
void KeyronaDeleteToken(KeyronaStorage &mySubjectStorage);

/*!
  *  @brief deletes a user in the database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaDeleteUser(KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief deletes a volume in the database
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaDeleteVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param groupParam, string, contains the calling parameter
  *  @param &myConfigfile, KeyronaConfigfile, contains the current Keyrona configuration
  */
void KeyronaGroupManagement     ( string groupParam, KeyronaConfigfile &myConfigfile );

/*!
  *  @brief imports a user in the database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  */
void KeyronaImportUser(KeyronaStorage &mySubjectStorage);

/*!
  *  @brief imports a volume in the database
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaImportVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param initParam, string, contains the calling parameter
  *  @param &myConfigfile, KeyronaConfigfile, contains the current Keyrona configuration
  */
void KeyronaInit     ( string initParam, KeyronaConfigfile &myConfigfile );

/*!
  *  @brief prints all admins to the screen
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @return bool, determines whether or not the operation was successful
  */
bool KeyronaListAdmins(KeyronaStorage &mySubjectStorage);

/*!
  *  @brief prints all groups to the screen
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  *  @return bool, determines whether or not the operation was successful
  */
bool KeyronaListGroups(KeyronaStorage &myGroupStorage, KeyronaStorage &mySubjectStorage);

/*!
  *  @brief prints all users to the screen
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param includeAdmins, determines wether or not admins should be included
  *  @return bool, determines whether or not the operation was successful
  */
bool KeyronaListUsers(KeyronaStorage &mySubjectStorage, bool includeAdmins);

/*!
  *  @brief prints all volumes to the screen
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @return bool, determines whether or not the operation was successful
  */
bool KeyronaListVolumes(KeyronaStorage &myVolumeStorage);

/*!
  *  @brief prints all groups in a given  volume to the screen
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaListGroupsInVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

/*!
  *  @brief prints all platforms to the screen
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @return bool, determines whether or not the operation was successful
  */
bool KeyronaListPlatforms(KeyronaStorage &mySubjectStorage);

/*!
  *  @brief returns all secret sharing schemes, that have access to a volume
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  *  @param &mySSSStorage, KeyronaStorage, points to the current secret sharing scheme database
  *  @return string, contains the sss, that have access
  */
string KeyronaListSSSInVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage, KeyronaStorage &mySSSStorage);

/*!
  *  @brief prints all subjects of a given group to the screen
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaListSubjectsInGroup(KeyronaStorage &myGroupStorage, KeyronaStorage &mySubjectStorage);

/*!
  *  @brief prints all subjects, that have access to given volume to the screen
  *  @param &myVolumeStorage, KeyronaStorage, points to the current volume database
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @param &myGroupStorage, KeyronaStorage, points to the current group database
  */
void KeyronaListSubjectsInVolume(KeyronaStorage &myVolumeStorage, KeyronaStorage &mySubjectStorage, KeyronaStorage &myGroupStorage);

void KeyronaShowESD				 ( KeyronaStorage &myESDStorage );

vector<int> KeyronaChooseAllPCR();

/*!
  *  @brief prints all tokens to the screen
  *  @param &mySubjectStorage, KeyronaStorage, points to the current subject database
  *  @return bool, determines whether or not the operation was successful
  */
bool KeyronaListToken(KeyronaStorage &mySubjectStorage);

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param platformParam, string, contains the calling parameter
  *  @param &myConfigfile, KeyronaConfigfile, contains the current Keyrona configuration
  */
void KeyronaPlatformManagement   ( string platformParam, KeyronaConfigfile &myConfigfile );

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param SSSParam, string, contains the calling parameter
  *  @param &myConfigfile, KeyronaConfigfile, contains the current Keyrona configuration
  */
void KeyronaSSSManagement        ( string SSSParam, KeyronaConfigfile &myConfigfile );

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param platformParam, string, contains the calling parameter
  *  @param &myConfigfile, KeyronaConfigfile, contains the current Keyrona configuration
  */
void KeyronaTokenManagement   ( string platformParam, KeyronaConfigfile &myConfigfile );

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param userParam, string, contains the calling parameter
  *  @param &myConfigfile, KeyronaConfigfile, contains the current Keyrona configuration
  */
void KeyronaUserManagement       ( string userParam, KeyronaConfigfile &myConfigfile );

/*!
  *  @brief parses the command line parameter and calls the according functions
  *  @param volumeParam, string, contains the calling parameter
  *  @param &myConfigfile, KeyronaConfigfile, contains the current Keyrona configuration
  */
void KeyronaVolumeManagement     ( string volumeParam, KeyronaConfigfile &myConfigfile );

void KeyronaESDManagement		 ( string esdParam, KeyronaConfigfile &myConfigfile );



// this method is actually implemented in KeyronaLogin.cxx
KeyronaSubject* getCurrentAdmin(KeyronaStorage &mySubjectStorage);

#endif	/* _KEYRONAMANAGER_HXX */
