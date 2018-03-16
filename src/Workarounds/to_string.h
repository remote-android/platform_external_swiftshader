/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// Cloned from master branch vendor/google/native/cmds/sysproxy/shared_ptr.h
// Upstream commit ff64c352c35c46a14f15503778781889a816eea4
// Upstream Change-Id: I481ec53b08beecde2bf6dc38e5933342235da3d9

#ifndef ANDROID_WORKAROUNDS_TO_STRING_H_
#define ANDROID_WORKAROUNDS_TO_STRING_H_

// Include this so that we fail badly if to_string is native.
#include <string>
#include <sstream>

namespace std {

template <typename T>
std::string to_string(const T& val) {
  std::ostringstream temp;
  temp << val;
  return temp.str();
}

}  // namespace std

#endif  // ANDROID_WORKAROUNDS_TO_STRING_H_
