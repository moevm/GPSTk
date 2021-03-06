//============================================================================
//
//  This file is part of GPSTk, the GPS Toolkit.
//
//  The GPSTk is free software; you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation; either version 3.0 of the License, or
//  any later version.
//
//  The GPSTk is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with GPSTk; if not, write to the Free Software Foundation,
//  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
//  
//  Copyright 2004, The University of Texas at Austin
//  Dagoberto Salazar - gAGE ( http://www.gage.es ). 2006, 2012
//
//============================================================================

//============================================================================
//
//This software developed by Applied Research Laboratories at the University of
//Texas at Austin, under contract to an agency or agencies within the U.S. 
//Department of Defense. The U.S. Government retains all rights to use,
//duplicate, distribute, disclose, or release this software. 
//
//Pursuant to DoD Directive 523024 
//
// DISTRIBUTION STATEMENT A: This software has been approved for public 
//                           release, distribution is unlimited.
//
//=============================================================================

/**
 * @file ExtractLC.hpp
 * This class eases LC combination data extraction from a Rinex3ObsData object.
 */

#ifndef GPSTK_EXTRACTLC_HPP
#define GPSTK_EXTRACTLC_HPP

#include "ExtractCombinationData.hpp"
#include "GNSSconstants.hpp"


namespace gpstk
{

      /// @ingroup RinexObs 
      //@{


      /// This class eases LC combination data extraction from
      /// a Rinex3ObsData object.
   class ExtractLC : public ExtractCombinationData
   {
   public:

         /// Default constructor
      ExtractLC()
         : typeObs1("L1"), typeObs2("L2")
      { valid = false; checkData = true; };


         /** Compute the LC observation from a Rinex3ObsData object.
          *
          * @param rinexData  The Rinex data set holding the observations.
          * @param hdr        RINEX Observation Header for current RINEX file.
          *
          * @return
          *    Number of satellites with LC combination data available.
          */
      virtual int getData( const Rinex3ObsData& rinexData,
                           const Rinex3ObsHeader& hdr )
         throw(InvalidRequest)
      {

         return ExtractCombinationData::getData( rinexData,
                                                 typeObs1,
                                                 typeObs2,
                                                 hdr );

      }; // End of method 'ExtractLC::getData()'


         /// Destructor
      virtual ~ExtractLC() {};


   protected:


         /// Compute the combination of observables.
      virtual double getCombination( double obs1, double obs2 )
         throw(InvalidRequest)
      {
         return ( (GAMMA_GPS*obs1*L1_WAVELENGTH - obs2*L2_WAVELENGTH) /
                  (GAMMA_GPS - 1.0) );
      };


   private:

      std::string typeObs1;
      std::string typeObs2;


   }; // End of class 'ExtractLC'

      //@}

}  // End of namespace gpstk

#endif   // GPSTK_EXTRACTLC_HPP
