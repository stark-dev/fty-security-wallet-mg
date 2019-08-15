/*  =========================================================================
    fty-security-wallet - generated layer of public API

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

#ifndef FTY_SECURITY_WALLET_LIBRARY_H_INCLUDED
#define FTY_SECURITY_WALLET_LIBRARY_H_INCLUDED

//  Set up environment for the application

//  External dependencies
#include <czmq.h>
#include <malamute.h>
#include <cxxtools/allocator.h>
#include <fty_log.h>
#include <fty_common_mlm.h>

//  FTY_SECURITY_WALLET version macros for compile-time API detection
#define FTY_SECURITY_WALLET_VERSION_MAJOR 1
#define FTY_SECURITY_WALLET_VERSION_MINOR 0
#define FTY_SECURITY_WALLET_VERSION_PATCH 0

#define FTY_SECURITY_WALLET_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define FTY_SECURITY_WALLET_VERSION \
    FTY_SECURITY_WALLET_MAKE_VERSION(FTY_SECURITY_WALLET_VERSION_MAJOR, FTY_SECURITY_WALLET_VERSION_MINOR, FTY_SECURITY_WALLET_VERSION_PATCH)

#if defined (__WINDOWS__)
#   if defined FTY_SECURITY_WALLET_STATIC
#       define FTY_SECURITY_WALLET_EXPORT
#   elif defined FTY_SECURITY_WALLET_INTERNAL_BUILD
#       if defined DLL_EXPORT
#           define FTY_SECURITY_WALLET_EXPORT __declspec(dllexport)
#       else
#           define FTY_SECURITY_WALLET_EXPORT
#       endif
#   elif defined FTY_SECURITY_WALLET_EXPORTS
#       define FTY_SECURITY_WALLET_EXPORT __declspec(dllexport)
#   else
#       define FTY_SECURITY_WALLET_EXPORT __declspec(dllimport)
#   endif
#   define FTY_SECURITY_WALLET_PRIVATE
#elif defined (__CYGWIN__)
#   define FTY_SECURITY_WALLET_EXPORT
#   define FTY_SECURITY_WALLET_PRIVATE
#else
#   if (defined __GNUC__ && __GNUC__ >= 4) || defined __INTEL_COMPILER
#       define FTY_SECURITY_WALLET_PRIVATE __attribute__ ((visibility ("hidden")))
#       define FTY_SECURITY_WALLET_EXPORT __attribute__ ((visibility ("default")))
#   else
#       define FTY_SECURITY_WALLET_PRIVATE
#       define FTY_SECURITY_WALLET_EXPORT
#   endif
#endif

//  Project has no stable classes, so we build the draft API
#undef  FTY_SECURITY_WALLET_BUILD_DRAFT_API
#define FTY_SECURITY_WALLET_BUILD_DRAFT_API

//  Opaque class structures to allow forward references
//  These classes are stable or legacy and built in all releases
//  Draft classes are by default not built in stable releases
#ifdef FTY_SECURITY_WALLET_BUILD_DRAFT_API
typedef struct _cam_credential_asset_mapping_t cam_credential_asset_mapping_t;
#define CAM_CREDENTIAL_ASSET_MAPPING_T_DEFINED
typedef struct _cam_accessor_t cam_accessor_t;
#define CAM_ACCESSOR_T_DEFINED
typedef struct _cam_exception_t cam_exception_t;
#define CAM_EXCEPTION_T_DEFINED
typedef struct _fty_credential_asset_mapping_server_t fty_credential_asset_mapping_server_t;
#define FTY_CREDENTIAL_ASSET_MAPPING_SERVER_T_DEFINED
typedef struct _secw_document_t secw_document_t;
#define SECW_DOCUMENT_T_DEFINED
typedef struct _secw_exception_t secw_exception_t;
#define SECW_EXCEPTION_T_DEFINED
typedef struct _secw_producer_accessor_t secw_producer_accessor_t;
#define SECW_PRODUCER_ACCESSOR_T_DEFINED
typedef struct _secw_consumer_accessor_t secw_consumer_accessor_t;
#define SECW_CONSUMER_ACCESSOR_T_DEFINED
typedef struct _secw_snmpv3_t secw_snmpv3_t;
#define SECW_SNMPV3_T_DEFINED
typedef struct _secw_snmpv1_t secw_snmpv1_t;
#define SECW_SNMPV1_T_DEFINED
typedef struct _secw_user_and_password_t secw_user_and_password_t;
#define SECW_USER_AND_PASSWORD_T_DEFINED
typedef struct _fty_security_wallet_mlm_agent_t fty_security_wallet_mlm_agent_t;
#define FTY_SECURITY_WALLET_MLM_AGENT_T_DEFINED
#endif // FTY_SECURITY_WALLET_BUILD_DRAFT_API


//  Public classes, each with its own header file
#ifdef FTY_SECURITY_WALLET_BUILD_DRAFT_API
#include "cam_credential_asset_mapping.h"
#include "cam_accessor.h"
#include "cam_exception.h"
#include "fty_credential_asset_mapping_server.h"
#include "secw_document.h"
#include "secw_exception.h"
#include "secw_producer_accessor.h"
#include "secw_consumer_accessor.h"
#include "secw_snmpv3.h"
#include "secw_snmpv1.h"
#include "secw_user_and_password.h"
#include "fty_security_wallet_mlm_agent.h"
#endif // FTY_SECURITY_WALLET_BUILD_DRAFT_API

#ifdef FTY_SECURITY_WALLET_BUILD_DRAFT_API

#ifdef __cplusplus
extern "C" {
#endif

//  Self test for private classes
FTY_SECURITY_WALLET_EXPORT void
    fty_security_wallet_private_selftest (bool verbose, const char *subtest);

#ifdef __cplusplus
}
#endif
#endif // FTY_SECURITY_WALLET_BUILD_DRAFT_API

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
