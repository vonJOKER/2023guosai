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

#include "heliodata.h"

using namespace std;

//helio data
helio_perf_data::helio_perf_data(){
	resetMetrics();
	n_metric = PERF_VALUES::_LAST;
}

double helio_perf_data::getDataByIndex(const int id){
	double rval;
	switch(id)
	{
		case helio_perf_data::PERF_VALUES::POWER_TO_REC:
			rval = power_to_rec;
			break;
		case helio_perf_data::PERF_VALUES::ETA_TOT:
			rval = eta_tot;
			break;
		case helio_perf_data::PERF_VALUES::ETA_COS:
			rval = eta_cos;
			break;
		case helio_perf_data::PERF_VALUES::ETA_ATT:
			rval = eta_att;
			break;
		case helio_perf_data::PERF_VALUES::ETA_INT:
			rval = eta_int;
			break;
		case helio_perf_data::PERF_VALUES::ETA_BLOCK:
			rval = eta_block;
			break;
		case helio_perf_data::PERF_VALUES::ETA_SHADOW:
			rval = eta_shadow;
			break;
		case helio_perf_data::PERF_VALUES::POWER_VALUE:
			rval = power_value;
			break;
		case helio_perf_data::PERF_VALUES::REFLECTIVITY:
			rval = reflectivity;
			break;
		case helio_perf_data::PERF_VALUES::SOILING:
			rval = soiling;
			break;
		case helio_perf_data::PERF_VALUES::RANK_METRIC:
			rval = rank_metric;
			break;
		case helio_perf_data::PERF_VALUES::REC_ABSORPTANCE:
			rval = rec_absorptance;
			break;
		case helio_perf_data::PERF_VALUES::ETA_CLOUD:
			rval = eta_cloud;
			break;
        case helio_perf_data::PERF_VALUES::ANNUAL_POWER:
            rval = energy_annual;
            break;
        case helio_perf_data::PERF_VALUES::ENERGY_VALUE:
            rval = energy_value;
            break;
        case helio_perf_data::PERF_VALUES::ANNUAL_EFFICIENCY:
            rval = eta_annual;
            break;
		default:
			rval = 0.;
	}	
	return rval;
}

void helio_perf_data::setDataByIndex(const int id, double value){
	
	switch(id)
	{
		case helio_perf_data::PERF_VALUES::ETA_ATT:
			eta_att = value;
			break;
		case helio_perf_data::PERF_VALUES::ETA_BLOCK:
			eta_block = value;
			break;
		case helio_perf_data::PERF_VALUES::ETA_COS:
			eta_cos = value;
			break;
		case helio_perf_data::PERF_VALUES::ETA_INT:
			eta_int = value;
			break;
		case helio_perf_data::PERF_VALUES::ETA_SHADOW:
			eta_shadow = value;
			break;
		case helio_perf_data::PERF_VALUES::ETA_TOT:
			eta_tot = value;
			break;
		case helio_perf_data::PERF_VALUES::REFLECTIVITY:
			reflectivity = value;
			break;
		case helio_perf_data::PERF_VALUES::SOILING:
			soiling = value;
			break;
		case helio_perf_data::PERF_VALUES::POWER_TO_REC:
			power_to_rec = value;
			break;
		case helio_perf_data::PERF_VALUES::POWER_VALUE:
			power_value = value;
			break;
		case helio_perf_data::PERF_VALUES::RANK_METRIC:
			rank_metric = value;
			break;
		case helio_perf_data::PERF_VALUES::REC_ABSORPTANCE:
			rec_absorptance = value;
			break;
		case helio_perf_data::PERF_VALUES::ETA_CLOUD:
			eta_cloud = value;
			break;
        case helio_perf_data::PERF_VALUES::ANNUAL_POWER:
            energy_annual = value;
            break;
        case helio_perf_data::PERF_VALUES::ENERGY_VALUE:
            energy_value = value;
            break;
        case helio_perf_data::PERF_VALUES::ANNUAL_EFFICIENCY:
            eta_annual = value;
            break;
	}	
}

void helio_perf_data::resetMetrics(){
	eta_tot = 0.;
	eta_cos = 1.;
	eta_att = 1.;
	eta_int = 1.;
	eta_block = 1.;
	eta_shadow = 1.;
	eta_cloud = 1.;
	power_to_rec = 0.;
	power_value = 0.;
	rank_metric = 0.;
    energy_value = 0.;
    energy_annual = 0.;
    eta_annual = 0.;
}

double helio_perf_data::calcTotalEfficiency(){
	eta_tot = eta_cos * eta_att * eta_int * eta_block * eta_shadow *reflectivity *soiling *eta_cloud; 
	return eta_tot;
}