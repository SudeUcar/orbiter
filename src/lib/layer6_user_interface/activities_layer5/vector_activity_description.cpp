/*
 * vector_activity_description.cpp
 *
 *  Created on: May 18, 2026
 *      Author: betten
 */






#include "orbiter_user_interface.h"

using namespace std;


namespace orbiter {
namespace layer6_user_interface {
namespace activities_layer5 {





vector_activity_description::vector_activity_description()
{
	Record_birth();

	f_report = false;

	f_missing_sets = false;
	missing_sets_n = 0;

}


vector_activity_description::~vector_activity_description()
{
	Record_death();
}


int vector_activity_description::read_arguments(
	int argc, std::string *argv,
	int verbose_level)
{
	int f_v = (verbose_level >= 1);
	int i;
	other::data_structures::string_tools ST;

	if (f_v) {
		cout << "vector_activity_description::read_arguments" << endl;
	}
	for (i = 0; i < argc; i++) {

		if (ST.stringcmp(argv[i], "-report") == 0) {
			f_report = true;
			if (f_v) {
				cout << "-report " << endl;
			}
		}
		else if (ST.stringcmp(argv[i], "-missing_sets") == 0) {
			f_missing_sets = true;
			missing_sets_n = ST.strtoi(argv[++i]);
			if (f_v) {
				cout << "-missing_sets " << missing_sets_n << endl;
			}
		}

		else if (ST.stringcmp(argv[i], "-end") == 0) {
			if (f_v) {
				cout << "-end" << endl;
			}
			break;
		}
		else {
			cout << "vector_activity_description::read_arguments "
					"unrecognized option " << argv[i] << endl;
			exit(1);
		}
	} // next i
	if (f_v) {
		cout << "vector_activity_description::read_arguments done" << endl;
	}
	return i + 1;
}

void vector_activity_description::print()
{
	if (f_report) {
		cout << "-report " << endl;
	}
	if (f_missing_sets) {
		cout << "-missing_sets " << missing_sets_n << endl;
	}


}





}}}


