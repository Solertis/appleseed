
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2017 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_FOUNDATION_UTILITY_VERSION_H
#define APPLESEED_FOUNDATION_UTILITY_VERSION_H

// appleseed.foundation headers.
#include "foundation/core/concepts/noncopyable.h"
#include "foundation/platform/types.h"

// appleseed.main headers.
#include "main/dllsymbol.h"

namespace foundation
{

//
// A version identifier.
//

typedef uint64 VersionID;


//
// An invalid version ID.
//

const VersionID InvalidVersionID = ~0;


//
// Format string for printing version identifiers to strings.
//

#define FMT_VERSION_ID "%llu"


//
// Base class for versionable objects.
//

class APPLESEED_DLLSYMBOL Versionable
  : public NonCopyable
{
  public:
    // Constructor.
    Versionable();

    // Return the version ID of this object.
    VersionID get_version_id() const;

    // Increase the version ID by 1.
    void bump_version_id();

  protected:
    VersionID m_version_id;
};


//
// Versionable class implementation.
//

inline Versionable::Versionable()
  : m_version_id(0)
{
}

inline VersionID Versionable::get_version_id() const
{
    return m_version_id;
}

inline void Versionable::bump_version_id()
{
    ++m_version_id;
}

}       // namespace foundation

#endif  // !APPLESEED_FOUNDATION_UTILITY_VERSION_H
