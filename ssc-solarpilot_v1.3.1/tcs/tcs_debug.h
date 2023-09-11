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

#include <stdio.h>
#include <string>
#include <vector>
#include "tcstype.h"

class stdfile
{
public:
	stdfile() : p(0) {  }
	stdfile(const char *file, const char *mode) { p = fopen(file, mode); }
	stdfile(const std::string &file, const char *mode) { p = fopen(file.c_str(), mode); }
//	stdfile(const wxString &file, const char *mode) { p = fopen((const char*)file.c_str(), mode); }
	~stdfile() { close(); }
	bool open(const char *file, const char *mode) { close(); p = fopen(file, mode); return ok(); }
	bool open(const std::string &file, const char *mode) { return open(file.c_str(), mode); }
	bool ok() { return 0 != p; }
	operator FILE*() const { return p; }
	void close() { if (p) ::fclose(p); p = 0; }
private:
	FILE *p;
};


static void debug_log_init_call(const char* unit_name, tcstypeinfo *type, std::vector<tcsvalue> &values)
{
	std::string fn ("C:\\Projects\\SAM\\Documentation\\CSP\\Linear Fresnel\\Molten Salt\\tcsdbg.txt");
	stdfile dbgout(fn, "a");

	fprintf(dbgout, "\n\n%s\n", unit_name);

	for (int i = 0; i < values.size(); i++)
	{
		fprintf(dbgout, "%s = ", type->variables[i].name);
		switch (values[i].type)
		{
		case TCS_NUMBER:
			fprintf(dbgout, "%lg\n", values[i].data.value);
			break;
		case TCS_ARRAY:
			fprintf(dbgout, "[ ");
			for (int j = 0; j < values[i].data.array.length-1; j++)
				fprintf(dbgout, "%lg, ", values[i].data.array.values[j]);
			fprintf(dbgout, "%lg ]\n", values[i].data.array.values[values[i].data.array.length - 1]);
			break;
		case TCS_MATRIX:
			fprintf(dbgout, "[\n[");
			for (int nr = 0; nr < values[i].data.matrix.nrows - 1; nr++)
			{
				for (int nc = 0; nc < values[i].data.matrix.ncols - 1; nc++)
					fprintf(dbgout, "%lg, ", values[i].data.matrix.values[nc + nr*values[i].data.matrix.ncols]);
				fprintf(dbgout, "%lg ],\n[", values[i].data.matrix.values[values[i].data.matrix.ncols - 1 + nr*values[i].data.matrix.ncols]);
			}
			for (int nc = 0; nc < values[i].data.matrix.ncols - 1; nc++)
				fprintf(dbgout, "%lg, ", values[i].data.matrix.values[nc + (values[i].data.matrix.nrows - 1 )* values[i].data.matrix.ncols]);
			fprintf(dbgout, "%lg ]\n]\n", values[i].data.matrix.values[values[i].data.matrix.ncols - 1 + (values[i].data.matrix.nrows - 1)*values[i].data.matrix.ncols]);
			break;
		case TCS_STRING:
			fprintf(dbgout, "%s\n", values[i].data.cstr);
			break;
		}
	}

	dbgout.close();
}
