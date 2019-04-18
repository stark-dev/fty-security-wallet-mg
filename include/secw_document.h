/*  =========================================================================
    secw_document - Document parsers

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
    =========================================================================
*/

#ifndef SECW_DOCUMENT_H_INCLUDED
#define SECW_DOCUMENT_H_INCLUDED

#include "cxxtools/serializationinfo.h"
#include <memory>
#include <functional>

namespace secw
{
    class Document;
    
    /**
     * Some typedef to make the code more clear
     */
    using Id            = std::string;
    using Tag           = std::string;
    using DocumentType  = std::string;
    using DocumentPtr   = std::shared_ptr<Document>;

    // FctDocumentFactory is returning a shared ptr of Doccument after building it using default contructor
    using FctDocumentFactory = std::function< DocumentPtr() >;

    /**
     * Some key definition for serialization
     * 
     */
    static constexpr const char* DOC_ID_ENTRY = "secw_doc_id";
    static constexpr const char* DOC_NAME_ENTRY = "secw_doc_name";
    static constexpr const char* DOC_TYPE_ENTRY = "secw_doc_type";
    static constexpr const char* DOC_TAGS_ENTRY = "secw_doc_tags";
    static constexpr const char* DOC_PUBLIC_ENTRY = "secw_doc_public";
    static constexpr const char* DOC_PRIVATE_ENTRY = "secw_doc_private";

    /**
     * \brief Document: Public interface
     */
    class Document
    {
    public:
        const std::string & getName() const;
        bool isContainingPrivateData() const;
        std::vector<Tag> getTags() const;

        const DocumentType & getType() const;
        const Id & getId() const;

        virtual DocumentPtr clone() const = 0;
        
        virtual ~Document(){/*log_debug("Cleaning document %s", m_name.c_str());*/}

        /**
         * \brief Give information if the object document contain private data or only the public data
         * 
         * \return true if the document contain private data
         */
        bool containPrivateData() const;

        /**
         * \brief Append the serialization of the document with header, public and private (secret) part.
         * 
         * \param cxxtools::SerializationInfo
         */
        void fillSerializationInfoWithSecret(cxxtools::SerializationInfo& si) const;

        /**
         * \brief Append the serialization of the document with header and public.
         * 
         * \param cxxtools::SerializationInfo
         */
        void fillSerializationInfoWithoutSecret(cxxtools::SerializationInfo& si) const;

    //Classe methods
        /**
         * \brief return the list of all supported types od documents
         * 
         * \return list of types
         */
        static std::vector<DocumentType> getSupportedTypes();

        /**
         * \brief return if we supported the Type
         * 
         * \param Type for check
         * \return true if we support the type
         */
        static bool isSupportedType(const DocumentType & type);
        
        static bool hasCommonTag(const std::vector<Tag> & tags1, const std::vector<Tag> & tags2);

        friend void operator>>= (const cxxtools::SerializationInfo& si, DocumentPtr & doc);
        
    protected:
        explicit Document(const DocumentType & type) :
            m_type(type)
        {}

        std::string m_name = "";
        DocumentType m_type = "";
        Id m_id = "";
        std::vector<Tag> m_tags;

        //This map is use to define the supported type and how to build them
        static std::map<DocumentType, FctDocumentFactory> m_documentFactoryFuntions;
        
        bool m_containPrivateData = true;

        virtual void fillSerializationInfoPrivateDoc(cxxtools::SerializationInfo& si) const = 0;
        virtual void fillSerializationInfoPublicDoc(cxxtools::SerializationInfo& si) const = 0;

        virtual void UpdatePrivateDocFromSerializationInfo(const cxxtools::SerializationInfo& si) = 0;
        virtual void UpdatePublicDocFromSerializationInfo(const cxxtools::SerializationInfo& si) = 0;
        
    private:
        void fillSerializationInfoHeaderDoc(cxxtools::SerializationInfo& si) const;

        void UpdateHeaderFromSerializationInfo(const cxxtools::SerializationInfo& si);

    };

    //save as fillSerializationInfoWithSecret
    void operator<<= (cxxtools::SerializationInfo& si, const Document & doc);
    void operator<<= (cxxtools::SerializationInfo& si, const DocumentPtr & doc);
    void operator>>= (const cxxtools::SerializationInfo& si, DocumentPtr & doc);

} // namepsace secw

#endif