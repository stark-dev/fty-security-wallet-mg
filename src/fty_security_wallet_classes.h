/*  =========================================================================
    fty_security_wallet_classes - private header file

    Copyright (C) 2019 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
    =========================================================================
*/

#ifndef FTY_SECURITY_WALLET_CLASSES_H_INCLUDED
#define FTY_SECURITY_WALLET_CLASSES_H_INCLUDED

//  Platform definitions, must come first
#include "platform.h"

//  External API
#include "../include/fty_security_wallet.h"

//  Opaque class structures to allow forward references
#ifndef CAM_CREDENTIAL_ASSET_MAPPING_STORAGE_T_DEFINED
typedef struct _cam_credential_asset_mapping_storage_t cam_credential_asset_mapping_storage_t;
#define CAM_CREDENTIAL_ASSET_MAPPING_STORAGE_T_DEFINED
#endif
#ifndef CAM_HELPERS_T_DEFINED
typedef struct _cam_helpers_t cam_helpers_t;
#define CAM_HELPERS_T_DEFINED
#endif
#ifndef SECW_SECURITY_WALLET_SERVER_T_DEFINED
typedef struct _secw_security_wallet_server_t secw_security_wallet_server_t;
#define SECW_SECURITY_WALLET_SERVER_T_DEFINED
#endif
#ifndef SECW_SECURITY_WALLET_T_DEFINED
typedef struct _secw_security_wallet_t secw_security_wallet_t;
#define SECW_SECURITY_WALLET_T_DEFINED
#endif
#ifndef SECW_PORTFOLIO_T_DEFINED
typedef struct _secw_portfolio_t secw_portfolio_t;
#define SECW_PORTFOLIO_T_DEFINED
#endif
#ifndef SECW_CLIENT_ACCESSOR_T_DEFINED
typedef struct _secw_client_accessor_t secw_client_accessor_t;
#define SECW_CLIENT_ACCESSOR_T_DEFINED
#endif
#ifndef SECW_HELPERS_T_DEFINED
typedef struct _secw_helpers_t secw_helpers_t;
#define SECW_HELPERS_T_DEFINED
#endif
#ifndef SECW_CONFIGURATION_T_DEFINED
typedef struct _secw_configuration_t secw_configuration_t;
#define SECW_CONFIGURATION_T_DEFINED
#endif

//  Extra headers

//  Internal API

#include "cam_credential_asset_mapping_storage.h"
#include "cam_helpers.h"
#include "secw_security_wallet_server.h"
#include "secw_security_wallet.h"
#include "secw_portfolio.h"
#include "secw_client_accessor.h"
#include "secw_helpers.h"
#include "secw_configuration.h"

//  *** To avoid double-definitions, only define if building without draft ***
#ifndef FTY_SECURITY_WALLET_BUILD_DRAFT_API

//  Self test for private classes
FTY_SECURITY_WALLET_PRIVATE void
    fty_security_wallet_private_selftest (bool verbose, const char *subtest);

#endif // FTY_SECURITY_WALLET_BUILD_DRAFT_API

#endif
