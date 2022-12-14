#include "XML_File_Intf.h"
#include "ace/XML_Utils/XML_Helper.h"
#include "ace/XML_Utils/XMLSchema/id_map.hpp"

#include "dds/DCPS/debug.h"

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

  QOS_XML_File_Handler::QOS_XML_File_Handler(XML::XML_Error_Handler* error_handler) :
    QOS_XML_Handler(),
    res_(new XML::XML_Schema_Resolver<XML::Environment_Resolver>()),
    eh_(error_handler ? error_handler : new XML::XML_Error_Handler()),
    helper_(res_,eh_)
  {
  }

  QOS_XML_File_Handler::~QOS_XML_File_Handler()
  {
    delete res_;
    delete eh_;
  }

  DDS::ReturnCode_t
  QOS_XML_File_Handler::init(const ACE_TCHAR * file)
  {
    DDS::ReturnCode_t retcode = DDS::RETCODE_OK;
    try
      {
        if (!helper_.is_initialized())
          {
            ACE_ERROR((LM_ERROR,
              ACE_TEXT("QOS_XML_File_Handler::init - ")
              ACE_TEXT("Unable to initialize XML_Helper.\n")));
            return DDS::RETCODE_ERROR;
          }

        if (DCPS_debug_level > 9)
          {
            ACE_DEBUG((LM_TRACE,
              ACE_TEXT("QOS_XML_File_Handler::init - ")
              ACE_TEXT("Constructing DOM\n")));
          }

        XERCES_CPP_NAMESPACE::DOMDocument *dom =
          helper_.create_dom(file);

        if (dom == 0)
          {
            if (DCPS_debug_level > 1)
              {
                ACE_ERROR((LM_ERROR,
                  ACE_TEXT("QOS_XML_File_Handler::init - ")
                  ACE_TEXT("Failed to open file %s\n"),
                  file));
              }
            return DDS::RETCODE_ERROR;
          }

        XERCES_CPP_NAMESPACE::DOMElement *profile_dom = dom->getDocumentElement();

        if (DCPS_debug_level > 9)
          {
            ACE_DEBUG((LM_TRACE,
              ACE_TEXT("QOS_XML_File_Handler::init - ")
              ACE_TEXT("DOMElement pointer: %u\n"), profile_dom));
          }

        ID_Map::TSS_ID_Map* TSS_ID_Map(ACE_Singleton<ID_Map::TSS_ID_Map, ACE_Null_Mutex>::instance());
        (*TSS_ID_Map)->reset();

        this->profiles_ = dds::reader::dds(dom);
      }
    catch (const CORBA::Exception &ex)
      {
        ACE_ERROR((LM_ERROR,
          ACE_TEXT("QOS_XML_File_Handler::init - ")
          ACE_TEXT("Caught CORBA exception whilst parsing XML <%s> into IDL: %C\n"),
          file,
          ex._info().c_str()));
        retcode = DDS::RETCODE_ERROR;
      }
    catch (...)
      {
        ACE_ERROR((LM_ERROR,
          ACE_TEXT("QOS_XML_File_Handler::init - ")
          ACE_TEXT("Unexpected exception whilst parsing XML <%s> into IDL.\n"),
          file));
        retcode = DDS::RETCODE_ERROR;
      }
    return retcode;
  }

  void
  QOS_XML_File_Handler::add_search_path(const ACE_TCHAR *environment,
                                        const ACE_TCHAR *relpath)
  {
    helper_.get_resolver().get_resolver().add_path(environment, relpath);
  }
}
}

NDDS_END_VERSIONED_NAMESPACE_DECL
