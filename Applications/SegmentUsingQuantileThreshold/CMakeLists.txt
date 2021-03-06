##############################################################################
#
# Library:   TubeTK
#
# Copyright 2010 Kitware Inc. 28 Corporate Drive,
# Clifton Park, NY, 12065, USA.
#
# All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
##############################################################################

set( MODULE_NAME SegmentUsingQuantileThreshold )
project( ${MODULE_NAME} )

if( NOT TubeTK_SOURCE_DIR )
  find_package( TubeTK REQUIRED )
  include( ${TubeTK_USE_FILE} )
endif( NOT TubeTK_SOURCE_DIR )

find_package( SlicerExecutionModel REQUIRED )
include( ${SlicerExecutionModel_USE_FILE} )

find_package( ITK REQUIRED )
if( TubeTK_BUILD_WITHIN_SLICER )
  set( ITK_NO_IO_FACTORY_REGISTER_MANAGER 1 )
endif( TubeTK_BUILD_WITHIN_SLICER )
include( ${ITK_USE_FILE} )

# Find Boost
set( Boost_ADDITIONAL_VERSIONS "1.51 1.52 1.53 1.54" )
set( Boost_USE_STATIC_LIBS ON )
set( Boost_USE_MULTITHREADED ON )
set( Boost_USE_STATIC_RUNTIME OFF )
find_package( Boost 1.49 COMPONENTS system filesystem REQUIRED )

# Fiddle with template-depth (for Boost's accumulators)
tubetk_append_if_absent(CMAKE_CXX_FLAGS "-ftemplate-depth-100")
tubetk_append_if_absent(CMAKE_CXX_FLAGS_RELEASE "-ftemplate-depth-100")
tubetk_append_if_absent(CMAKE_CXX_FLAGS_DEBUG "-ftemplate-depth-100")
tubetk_append_if_absent(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-ftemplate-depth-100")

SEMMacroBuildCLI(
  NAME ${MODULE_NAME}
  LOGO_HEADER ${TubeTK_SOURCE_DIR}/Base/CLI/TubeTKLogo.h
  TARGET_LIBRARIES
    ${ITK_LIBRARIES}
    TubeCLI TubeTKCommon
  INCLUDE_DIRECTORIES
    ${Boost_INCLUDE_DIRS} )

if( BUILD_TESTING )
  add_subdirectory( Testing )
endif( BUILD_TESTING )
