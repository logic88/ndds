/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_DCPS_WRITERDATASAMPLELIST_H
#define NDDS_DCPS_WRITERDATASAMPLELIST_H

#include "dcps_export.h"

#include <cstring>

NDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace NDDS {
namespace DCPS {

class DataSampleElement;

/**
* A list of DataSampleElement pointers to be queued by the order the
* samples are written to the DataWriter (within PRESENTATION.access_scope==TOPIC).
* Cache the number of elements in the list so that list traversal is
* not required to find this information.
* Manages DataSampleElement's previous_writer_sample/next_writer_sample pointers
*/
class NDDS_Dcps_Export WriterDataSampleList {
public:

  /// Default constructor clears the list.
  WriterDataSampleList();
  ~WriterDataSampleList() {}

  /// Reset to initial state.
  void reset();

  ssize_t size() const;
  DataSampleElement* head() const;
  DataSampleElement* tail() const;

  void enqueue_tail(const DataSampleElement* element);

  bool dequeue_head(DataSampleElement*& stale);

  bool dequeue(const DataSampleElement* stale);

protected:

   /// The first element of the list.
   DataSampleElement* head_;

   /// The last element of the list.
   DataSampleElement* tail_;

   /// Number of elements in the list.
   ssize_t size_;
   //TBD size is never negative so should be size_t but this ripples through
   // the transport code so leave it for now. SHH
};


} // namespace DCPS
} // namespace NDDS

NDDS_END_VERSIONED_NAMESPACE_DECL

#if defined(__ACE_INLINE__)
#include "WriterDataSampleList.inl"
#endif /* __ACE_INLINE__ */

#endif  /* NDDS_DCPS_WRITERDATASAMPLELIST_H */
