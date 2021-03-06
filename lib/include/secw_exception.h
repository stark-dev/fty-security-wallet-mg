/*  =========================================================================
    secw_exception - secw exception

    Copyright (C) 2019 - 2020 Eaton

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
    =========================================================================
*/

#pragma once

#include <exception>
#include <string>
#include "secw_document.h"

namespace cxxtools {
class SerializationInfo;
}

namespace secw {

enum ErrorCode : uint8_t
{
    GENERIC = 0,
    UNSUPPORTED_COMMAND,
    PROTOCOL_ERROR,
    BAD_COMMAND_ARGUMENT,
    UNKNOWN_DOCUMENT_TYPE,
    UNKNOWN_PORTFOLIO,
    INVALID_DOCUMENT_FORMAT,
    IMPOSSIBLE_TO_LOAD_PORTFOLIO,
    UNKNOWN_TAG,
    DOCUMENT_DO_NOT_EXIST,
    ILLEGAL_ACCESS,
    UNKNOWN_USAGE_ID,
    NAME_ALREADY_EXISTS,
    NAME_DOES_NOT_EXIST,
    MLM_CLIENT_IS_NULL,
    MLM_INTERRUPTED,
    MLM_FAILED
};

// =====================================================================================================================

class SecwException : public std::exception
{
public:
    explicit SecwException(const std::string& whatArg, ErrorCode code = ErrorCode::GENERIC);

    virtual ~SecwException()
    {
    }

    const char* what() const noexcept override;

    inline ErrorCode getErrorCode() const
    {
        return m_code;
    }

    // return an error payload from an exception
    std::string toJson() const;

    friend void operator<<=(cxxtools::SerializationInfo& si, const SecwException& exception);

    // throw the good exception base on the error payload
    static void throwSecwException(const std::string& data);

protected:
    virtual void fillSerializationInfo(cxxtools::SerializationInfo& si) const;

private:
    ErrorCode   m_code;
    std::string m_whatArg;
};

void operator<<=(cxxtools::SerializationInfo& si, const SecwException& exception);

// =====================================================================================================================

/// Command is not supported
class SecwUnsupportedCommandException : public SecwException
{
public:
    explicit SecwUnsupportedCommandException(const std::string& whatArg)
        : SecwException(whatArg, ErrorCode::UNSUPPORTED_COMMAND)
    {
    }
};

// =====================================================================================================================

/// Wrong message format => the message do not comply to the protocol
class SecwProtocolErrorException : public SecwException
{
public:
    explicit SecwProtocolErrorException(const std::string& whatArg)
        : SecwException(whatArg, ErrorCode::PROTOCOL_ERROR)
    {
    }
};

// =====================================================================================================================

/// Arguments for the command are not good
class SecwBadCommandArgumentException : public SecwException
{
public:
    explicit SecwBadCommandArgumentException(const std::string& whatArg)
        : SecwException(whatArg, ErrorCode::BAD_COMMAND_ARGUMENT)
    {
    }
};

// =====================================================================================================================

/// Type of document is unknown
class SecwUnknownDocumentTypeException : public SecwException
{
private:
    std::string m_documentType;

    void fillSerializationInfo(cxxtools::SerializationInfo& si) const override;

public:
    explicit SecwUnknownDocumentTypeException(const std::string& documentType);
    SecwUnknownDocumentTypeException(const cxxtools::SerializationInfo& extraData, const std::string& whatArg);

    inline std::string getDocumentType() const
    {
        return m_documentType;
    }
};

// =====================================================================================================================

/// Portfolio is unknown
class SecwUnknownPortfolioException : public SecwException
{
private:
    std::string m_portfolioName;

    void fillSerializationInfo(cxxtools::SerializationInfo& si) const override;

public:
    explicit SecwUnknownPortfolioException(const std::string& portfolioName);
    SecwUnknownPortfolioException(const cxxtools::SerializationInfo& extraData, const std::string& whatArg);

    inline std::string getPortfolioName() const
    {
        return m_portfolioName;
    }
};

// =====================================================================================================================

/// Invalid format of document
class SecwInvalidDocumentFormatException : public SecwException
{
private:
    std::string m_documentField;

    void fillSerializationInfo(cxxtools::SerializationInfo& si) const override;

public:
    explicit SecwInvalidDocumentFormatException(const std::string& documentField);
    SecwInvalidDocumentFormatException(const cxxtools::SerializationInfo& extraData, const std::string& whatArg);

    inline std::string getDocumentField() const
    {
        return m_documentField;
    }
};

// =====================================================================================================================

/// Impossible to load the portfolio
class SecwImpossibleToLoadPortfolioException : public SecwException
{
public:
    explicit SecwImpossibleToLoadPortfolioException(const std::string& whatArg)
        : SecwException(whatArg, ErrorCode::IMPOSSIBLE_TO_LOAD_PORTFOLIO)
    {
    }
};

// =====================================================================================================================

/// Tag is unknown
class SecwUnknownTagException : public SecwException
{
public:
    explicit SecwUnknownTagException(const std::string& whatArg)
        : SecwException(whatArg, ErrorCode::UNKNOWN_TAG)
    {
    }
};

// =====================================================================================================================

/// document do not exist
class SecwDocumentDoNotExistException : public SecwException
{
private:
    Id m_documentId;

    void fillSerializationInfo(cxxtools::SerializationInfo& si) const override;

public:
    explicit SecwDocumentDoNotExistException(const Id& documentId);
    SecwDocumentDoNotExistException(const cxxtools::SerializationInfo& extraData, const std::string& whatArg);

    inline Id getDocumentId() const
    {
        return m_documentId;
    }
};

// =====================================================================================================================

/// Illegal action by the client
class SecwIllegalAccess : public SecwException
{
public:
    explicit SecwIllegalAccess(const std::string& whatArg)
        : SecwException(whatArg, ErrorCode::ILLEGAL_ACCESS)
    {
    }
};

// =====================================================================================================================

/// Usage ID is unknown
class SecwUnknownUsageIDException : public SecwException
{
private:
    UsageId m_usageId;

    void fillSerializationInfo(cxxtools::SerializationInfo& si) const override;

public:
    explicit SecwUnknownUsageIDException(const UsageId& usageId);
    SecwUnknownUsageIDException(const cxxtools::SerializationInfo& extraData, const std::string& whatArg);

    inline UsageId getUsageId() const
    {
        return m_usageId;
    }
};

// =====================================================================================================================

/// Name already exist
class SecwNameAlreadyExistsException : public SecwException
{
private:
    std::string m_name;

    void fillSerializationInfo(cxxtools::SerializationInfo& si) const override;

public:
    explicit SecwNameAlreadyExistsException(const std::string& name);
    SecwNameAlreadyExistsException(const cxxtools::SerializationInfo& extraData, const std::string& whatArg);

    inline std::string getName() const
    {
        return m_name;
    }
};

// =====================================================================================================================

/// Name does not exist
class SecwNameDoesNotExistException : public SecwException
{
private:
    std::string m_name;

    void fillSerializationInfo(cxxtools::SerializationInfo& si) const override;

public:
    explicit SecwNameDoesNotExistException(const std::string& name);
    SecwNameDoesNotExistException(const cxxtools::SerializationInfo& extraData, const std::string& whatArg);

    inline std::string getName() const
    {
        return m_name;
    }
};

// =====================================================================================================================

/// Malamute client is null
class SecwMalamuteClientIsNullException : public SecwException
{
public:
    explicit SecwMalamuteClientIsNullException()
        : SecwException("Malamute client is null", ErrorCode::MLM_CLIENT_IS_NULL)
    {
    }
};

// =====================================================================================================================

/// Malamute Interrupted
class SecwMalamuteInterruptedException : public SecwException
{
public:
    explicit SecwMalamuteInterruptedException()
        : SecwException("Malamute interrupted", ErrorCode::MLM_INTERRUPTED)
    {
    }
};

// =====================================================================================================================

/// Malamute Connection Failed Exception
class SecwMalamuteConnectionFailedException : public SecwException
{
public:
    explicit SecwMalamuteConnectionFailedException()
        : SecwException("Malamute Connection Failed", ErrorCode::MLM_FAILED)
    {
    }
};

// =====================================================================================================================

} // namespace secw
