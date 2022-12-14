/*
 * Distributed under the NDDS License.
 * See: http://www.NDDS.org/license.html
 */

#ifndef NDDS_DCPS_SECURITY_ACCESS_CONTROL_XML_UTILS_H
#define NDDS_DCPS_SECURITY_ACCESS_CONTROL_XML_UTILS_H

#include "DomainIdSet.h"

#include <dds/Versioned_Namespace.h>
#include <dds/DCPS/SafetyProfileStreams.h>
#include <dds/DCPS/unique_ptr.h>
#include <dds/DCPS/security/NDDS_Security_Export.h>

#include <ace/XML_Utils/XercesString.h>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLDateTime.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/SAXParseException.hpp>

#include <string>
#include <ctime>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace Security {
namespace XmlUtils {

typedef DCPS::unique_ptr<xercesc::XercesDOMParser> ParserPtr;

NDDS_Security_Export
bool get_parser(ParserPtr& parser, const std::string& filename, const std::string& xml);

NDDS_Security_Export
std::string to_string(const XMLCh* in);

NDDS_Security_Export
bool parse_bool(const XMLCh* in, bool& value);

NDDS_Security_Export
bool parse_time(const XMLCh* in, time_t& value);

NDDS_Security_Export
std::string to_string(const xercesc::SAXParseException& ex);

inline std::string to_string(const xercesc::XMLException& ex)
{
  return to_string(ex.getMessage());
}

inline std::string to_string(const xercesc::DOMException& ex)
{
  return to_string(ex.getMessage());
}

inline std::string to_string(const xercesc::DOMNode* node)
{
  return to_string(node->getTextContent());
}

inline bool parse_bool(const xercesc::DOMNode* node, bool& value)
{
  return parse_bool(node->getTextContent(), value);
}

inline bool parse_time(const xercesc::DOMNode* node, time_t& value)
{
  return parse_time(node->getTextContent(), value);
}

/**
 * Convert a node that's a DomainIdSet in the permissions and governance XML
 * Schema in the security spec to a std::set of domain ids.
 */
NDDS_Security_Export
bool parse_domain_id_set(const xercesc::DOMNode* node, Security::DomainIdSet& domain_id_set);

inline bool is_element(const xercesc::DOMNode* node)
{
  return node->getNodeType() == xercesc::DOMNode::ELEMENT_NODE;
}

} // namespace XMLUtils
} // namespace Security
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#endif
