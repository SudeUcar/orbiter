/*
 * classification_of_cubic_surfaces_with_double_sixes_activity.cpp
 *
 *  Created on: Apr 1, 2021
 *      Author: betten
 */


#include "orbiter_user_interface.h"

using namespace std;


namespace orbiter {
namespace layer6_user_interface {
namespace activities_layer5 {


classification_of_cubic_surfaces_with_double_sixes_activity::classification_of_cubic_surfaces_with_double_sixes_activity()
{
	Record_birth();
	Descr = NULL;
	SCW = NULL;
}

classification_of_cubic_surfaces_with_double_sixes_activity::~classification_of_cubic_surfaces_with_double_sixes_activity()
{
	Record_death();
}

void classification_of_cubic_surfaces_with_double_sixes_activity::init(
		classification_of_cubic_surfaces_with_double_sixes_activity_description
			*Descr,
			layer5_applications::applications_in_algebraic_geometry::cubic_surfaces_and_double_sixes::surface_classify_wedge *SCW,
		int verbose_level)
{
	int f_v = (verbose_level >= 1);

	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::init" << endl;
	}

	classification_of_cubic_surfaces_with_double_sixes_activity::Descr = Descr;
	classification_of_cubic_surfaces_with_double_sixes_activity::SCW = SCW;

	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::init done" << endl;
	}
}

void classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity(
		int verbose_level)
{
	int f_v = (verbose_level >= 1);

	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity" << endl;
	}
	if (Descr->f_report) {
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"-report" << endl;
			cout << "SCW->Surf->n = " << SCW->Surf->n << endl;
		}
		report(Descr->report_options, verbose_level);
	}
	else if (Descr->f_stats) {
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"-stats" << endl;
		}
		SCW->stats(Descr->stats_prefix, verbose_level - 1);
	}
	else if (Descr->f_identify_Eckardt) {
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before SCW->identify_Eckardt_and_print_table" << endl;
		}
		SCW->identify_Eckardt_and_print_table(verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after SCW->identify_Eckardt_and_print_table" << endl;
		}

	}
	else if (Descr->f_identify_F13) {
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before SCW->identify_F13_and_print_table" << endl;
		}
		SCW->identify_F13_and_print_table(verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after SCW->identify_F13_and_print_table" << endl;
		}
	}
	else if (Descr->f_identify_Bes) {
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before SCW->identify_Bes_and_print_table" << endl;
		}
		SCW->identify_Bes_and_print_table(verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after SCW->identify_Bes_and_print_table" << endl;
		}
	}
	else if (Descr->f_identify_general_abcd) {
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before SCW->identify_general_abcd_and_print_table" << endl;
		}
		SCW->identify_general_abcd_and_print_table(verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after SCW->identify_general_abcd_and_print_table" << endl;
		}
	}
	else if (Descr->f_isomorphism_testing) {

		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before SCW->test_isomorphism" << endl;
		}
		SCW->test_isomorphism(
				Descr->isomorphism_testing_surface1_label,
				Descr->isomorphism_testing_surface2_label,
				verbose_level);

		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after SCW->test_isomorphism" << endl;
		}


	}
	else if (Descr->f_recognize) {
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before SCW->recognition" << endl;
		}
		SCW->recognition(
				Descr->recognize_surface_label,
				verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after SCW->recognition" << endl;
		}

	}
	else if (Descr->f_create_source_code) {
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before SCW->Surface_repository->generate_source_code" << endl;
		}
		SCW->Surface_repository->generate_source_code(verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after SCW->Surface_repository->generate_source_code" << endl;
		}
	}
	else if (Descr->f_sweep_Cayley) {

		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"f_sweep_Cayley" << endl;
		}
		int f_break_early = false;

		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before SCW->sweep_Cayley" << endl;
		}
		SCW->sweep_Cayley(f_break_early, verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after SCW->sweep_Cayley" << endl;
		}
	}
	else if (Descr->f_sweep_Sylvester) {


		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"f_sweep_Sylvester" << endl;
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"options = " << Descr->sweep_Sylvester_options << endl;
		}



		long int *Plane5_ranks;
		int nb_types;

		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before get_plane5_ranks" << endl;
		}
		get_plane5_ranks(
				Descr->sweep_Sylvester_fname, Descr->sweep_Sylvester_col_label,
				Plane5_ranks,
				nb_types,
				verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after get_plane5_ranks" << endl;
		}

		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before SCW->sweep_Sylvester" << endl;
		}
		SCW->sweep_Sylvester(Plane5_ranks, nb_types, Descr->sweep_Sylvester_options, verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after SCW->sweep_Sylvester" << endl;
		}

		FREE_lint(Plane5_ranks);

	}
	else if (Descr->f_Sylvester_pentahedral_form_after_sweep) {


		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"f_Sylvester_pentahedral_form_after_sweep" << endl;
		}


		long int *Plane5_ranks;
		int nb_types;

		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before get_plane5_ranks" << endl;
		}
		get_plane5_ranks(
				Descr->Sylvester_pentahedral_form_after_sweep_fname,
				Descr->Sylvester_pentahedral_form_after_sweep_col_label,
				Plane5_ranks,
				nb_types,
				verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after get_plane5_ranks" << endl;
		}

		long int *Pentahedron5_ranks;
		int *Pentahedron5_coeffs; // [20]
		int *linear_combination5; //[5]


		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"before SCW->Sylvester_pentahedral_form_after_sweep" << endl;
		}
		SCW->Sylvester_pentahedral_form_after_sweep(
				Descr->Sylvester_pentahedral_form_after_sweep_surface_label,
				Plane5_ranks, nb_types,
				Pentahedron5_ranks,
				Pentahedron5_coeffs,
				linear_combination5,
				verbose_level);
		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"after SCW->Sylvester_pentahedral_form_after_sweep" << endl;
		}

		if (f_v) {
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"plane coeffs: " << endl;
			Int_matrix_print(Pentahedron5_coeffs, 5, 4);
			cout << "classification_of_cubic_surfaces_with_double_sixes_activity::perform_activity "
					"linear combination: " << endl;
			Int_vec_print(cout, linear_combination5, 5);
			cout << endl;
		}
	}

}


void classification_of_cubic_surfaces_with_double_sixes_activity::get_plane5_ranks(
		std::string &fname, std::string &col_label,
		long int *&Plane5_ranks,
		int &nb_types,
		int verbose_level)
{
	int f_v = (verbose_level >= 1);

	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::get_plane5_ranks" << endl;
	}

	other::orbiter_kernel_system::file_io Fio;

	other::data_structures::set_of_sets *SoS;

	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::get_plane5_ranks fname = " << fname << endl;
	}
	Fio.Csv_file_support->read_column_as_set_of_sets(
			fname, col_label,
			SoS,
			verbose_level);

	if (!SoS->has_constant_size_property()) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::get_plane5_ranks the data does not have constant size" << endl;
		exit(1);
	}

	if (SoS->get_constant_size() != 5) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::get_plane5_ranks the data must have size 5" << endl;
		exit(1);
	}



	int i;

	nb_types = SoS->nb_sets;

	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::get_plane5_ranks "
				"nb plane types = " << nb_types << endl;
	}

	Plane5_ranks = NEW_lint(nb_types * 5);
	for (i = 0; i < nb_types; i++) {
		Lint_vec_copy(SoS->Sets[i], Plane5_ranks + i * 5, 5);
	}

	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::get_plane5_ranks "
				"planes:" << endl;
		Lint_matrix_print(Plane5_ranks, nb_types, 5);
	}

	FREE_OBJECT(SoS);

	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::get_plane5_ranks done" << endl;
	}
}

void classification_of_cubic_surfaces_with_double_sixes_activity::report(
		std::string &options,
		int verbose_level)
{
	int f_v = (verbose_level >= 1);

	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::report" << endl;
	}



	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::report "
				"before SCW->create_report" << endl;
		cout << "SCW->Surf->n = " << SCW->Surf->n << endl;
	}
	SCW->create_report(
			options,
			verbose_level - 1);
	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::report "
				"after SCW->create_report" << endl;
	}
	if (f_v) {
		cout << "classification_of_cubic_surfaces_with_double_sixes_activity::report done" << endl;
	}
}








}}}



