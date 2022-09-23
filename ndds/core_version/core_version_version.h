/*
 *
 *
 * Distributed under the NDDS License.
 * See: http://www.ndds.org/license.html
 */

#ifndef NDDS_VERSION_H
#define NDDS_VERSION_H

#define NDDS_MAJOR_VERSION 3
#define NDDS_MINOR_VERSION 20
#define NDDS_MICRO_VERSION 0
#define NDDS_VERSION_METADATA ""
#define NDDS_IS_RELEASE 1
#define NDDS_VERSION "3.20.0"

#define NDDS_VERSION_AT_LEAST(MAJOR, MINOR, MICRO) (\
  (NDDS_MAJOR_VERSION > (MAJOR)) || \
  (NDDS_MAJOR_VERSION == (MAJOR) && NDDS_MINOR_VERSION >= (MINOR)) || \
  (NDDS_MAJOR_VERSION == (MAJOR) && NDDS_MINOR_VERSION == (MINOR) && \
    (NDDS_MICRO_VERSION >= (MICRO)) \
  ) \
)

#define NDDS_VERSION_EXACTLY(MAJOR, MINOR, MICRO) (NDDS_MAJOR_VERSION == (MAJOR) && \
  NDDS_MINOR_VERSION == (MINOR) && NDDS_MICRO_VERSION == (MICRO))

#define NDDS_VERSION_LESS_THAN(MAJOR, MINOR, MICRO) \
  !NDDS_VERSION_AT_LEAST((MAJOR), (MINOR), (MICRO))

// NOTE: These are deprecated
// lint.pl ignores nonprefixed_public_macros on next line
#define DDS_MAJOR_VERSION (NDDS_MAJOR_VERSION)
// lint.pl ignores nonprefixed_public_macros on next line
#define DDS_MINOR_VERSION (NDDS_MINOR_VERSION)
// lint.pl ignores nonprefixed_public_macros on next line
#define DDS_MICRO_VERSION (NDDS_MICRO_VERSION)
// lint.pl ignores nonprefixed_public_macros on next line
#define DDS_VERSION (NDDS_VERSION)

#endif // NDDS_VERSION_H
