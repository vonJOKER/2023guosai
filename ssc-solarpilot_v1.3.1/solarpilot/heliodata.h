/*******************************************************************************************************
*  Copyright 2017 Alliance for Sustainable Energy, LLC
*
*  NOTICE: This software was developed at least in part by Alliance for Sustainable Energy, LLC
*  (�Alliance�) under Contract No. DE-AC36-08GO28308 with the U.S. Department of Energy and the U.S.
*  The Government retains for itself and others acting on its behalf a nonexclusive, paid-up,
*  irrevocable worldwide license in the software to reproduce, prepare derivative works, distribute
*  copies to the public, perform publicly and display publicly, and to permit others to do so.
*
*  Redistribution and use in source and binary forms, with or without modification, are permitted
*  provided that the following conditions are met:
*
*  1. Redistributions of source code must retain the above copyright notice, the above government
*  rights notice, this list of conditions and the following disclaimer.
*
*  2. Redistributions in binary form must reproduce the above copyright notice, the above government
*  rights notice, this list of conditions and the following disclaimer in the documentation and/or
*  other materials provided with the distribution.
*
*  3. The entire corresponding source code of any redistribution, with or without modification, by a
*  research entity, including but not limited to any contracting manager/operator of a United States
*  National Laboratory, any institution of higher learning, and any non-profit organization, must be
*  made publicly available under this license for as long as the redistribution is made available by
*  the research entity.
*
*  4. Redistribution of this software, without modification, must refer to the software by the same
*  designation. Redistribution of a modified version of this software (i) may not refer to the modified
*  version by the same designation, or by any confusingly similar designation, and (ii) must refer to
*  the underlying software originally provided by Alliance as �System Advisor Model� or �SAM�. Except
*  to comply with the foregoing, the terms �System Advisor Model�, �SAM�, or any confusingly similar
*  designation may not be used to refer to any modified version of this software or any modified
*  version of the underlying software originally provided by Alliance without the prior written consent
*  of Alliance.
*
*  5. The name of the copyright holder, contributors, the United States Government, the United States
*  Department of Energy, or any of their employees may not be used to endorse or promote products
*  derived from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
*  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
*  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER,
*  CONTRIBUTORS, UNITED STATES GOVERNMENT OR UNITED STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR
*  EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
*  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
*  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
*  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************************************/

#ifndef _HELIODATA_
#define _HELIODATA_ 1

#include <vector>

struct helio_perf_data
{
private:
	std::vector<double*> _dvars;
public:
	//Power to receiver=0;Total efficiency=1;Cosine efficiency=2;Attenuation efficiency=3;Intercept efficiency=4;Blocking efficiency=5;Shadowing efficiency=6;TOU-weighted power=7
	
	//This enumeration is order specific based on the indices specified in the gui variable "solarfield.0.hsort_method"
	struct PERF_VALUES { enum A {
		POWER_TO_REC=0, ETA_TOT, ETA_COS, ETA_ATT, ETA_INT, ETA_BLOCK, ETA_SHADOW, POWER_VALUE, /* after this, order not significant */
        REFLECTIVITY, SOILING, REC_ABSORPTANCE, RANK_METRIC, ETA_CLOUD, ANNUAL_POWER, ENERGY_VALUE, ANNUAL_EFFICIENCY, _LAST };
	};
	helio_perf_data();

	void resetMetrics();
	double calcTotalEfficiency();
	
	double getDataByIndex( const int id );
	void setDataByIndex( const int id, double value);
	int n_metric;
    double
        eta_cos,	//[-] Heliostat cosine efficiency
        eta_att,	//[-] Atmospheric attenuation efficiency
        eta_int,	//[-] Intercept efficiency
        eta_block,  //[-] Blocking efficiency
        eta_shadow, //[-] Shadowing efficiency
        eta_tot,	//[-] Total heliostat intercept
        reflectivity,
        soiling,
        rec_absorptance,	//Absorptance of the receiver this heliostat is aiming at
        power_to_rec,	//[W] delivered power
        power_value,
        rank_metric,	//Power weighted by the payment allocation factor, if applicable
        eta_cloud,	//[-] Loss due to cloudiness (performance simulation only)
        energy_value, //[Wh] energy delivered over the simulation time period
        energy_annual, //[Wh] estimated total annual energy for the heliostat
        eta_annual; //[-] estimated annual total efficiency
		
};

#endif