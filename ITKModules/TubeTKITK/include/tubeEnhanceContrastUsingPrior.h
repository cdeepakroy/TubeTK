/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
*=========================================================================*/
#ifndef __tubeEnhanceContrastUsingPrior_h
#define __tubeEnhanceContrastUsingPrior_h

#include "itktubeEnhanceContrastUsingPriorImageFilter.h"
#include "tubeWrappingMacros.h"
#include "itkObject.h"


namespace tube
{
/** \class EnhanceContrastUsingPrior
 *
 *  \ingroup TubeTKITK
 */

template< class TPixel, unsigned int VDimension >
class EnhanceContrastUsingPrior:
  public itk::Object
{
public:
  /** Standard class typedefs. */
  typedef EnhanceContrastUsingPrior       Self;
  typedef itk::SmartPointer< Self >       Pointer;
  typedef itk::SmartPointer< const Self > ConstPointer;

  typedef itk::tube::EnhanceContrastUsingPriorImageFilter
    < TPixel, VDimension >                FilterType;

  typedef typename FilterType::ImageType           ImageType;
  typedef typename ImageType::ConstPointer         ConstImagePointer;
  typedef typename ImageType::Pointer              ImagePointer;

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  /** Run-time type information (and related methods). */
  itkTypeMacro( EnhanceContrastUsingPrior, Object );

  /* Set input image */
  tubeWrapSetConstObjectMacro( Input, ImageType, Filter );

  /** Set/Get input Mask Image */
  tubeWrapSetObjectMacro( InputMaskImage, ImageType, Filter );
  tubeWrapGetObjectMacro( InputMaskImage, ImageType, Filter );

  /** Set/Get Object Scale */
  tubeWrapSetMacro( ObjectScale, float, Filter );
  tubeWrapGetMacro( ObjectScale, float, Filter );

  /** Set/Get Background Scale */
  tubeWrapSetMacro( BackgroundScale, float, Filter );
  tubeWrapGetMacro( BackgroundScale, float, Filter );

  /** Set/Get Mask Object Value */
  tubeWrapSetMacro( MaskObjectValue, int, Filter );
  tubeWrapGetMacro( MaskObjectValue, int, Filter );

  /** Set/Get Mask Background Value */
  tubeWrapSetMacro( MaskBackgroundValue, int, Filter );
  tubeWrapGetMacro( MaskBackgroundValue, int, Filter );

  /** Set/Get Optimization Iterations */
  tubeWrapSetMacro( OptimizationIterations, int, Filter );
  tubeWrapGetMacro( OptimizationIterations, int, Filter );

  /** Set/Get Optimization Seed */
  tubeWrapSetMacro( OptimizationSeed, int, Filter );
  tubeWrapGetMacro( OptimizationSeed, int, Filter );

  tubeWrapGetObjectMacro( Output, ImageType, Filter );

  /* Runs tubes to image conversion */
  tubeWrapUpdateMacro( Filter );

protected:
  EnhanceContrastUsingPrior( void );
  ~EnhanceContrastUsingPrior() {}
  void PrintSelf( std::ostream & os, itk::Indent indent ) const;

private:
  /** itkConvertSpatialGraphToImageFilter parameters **/
  EnhanceContrastUsingPrior( const Self & );
  void operator=( const Self & );

  typename FilterType::Pointer  m_Filter;
};
} // End namespace tube

#ifndef ITK_MANUAL_INSTANTIATION
#include "tubeEnhanceContrastUsingPrior.hxx"
#endif

#endif // End !defined( __tubeEnhanceContrastUsingPrior_h )
