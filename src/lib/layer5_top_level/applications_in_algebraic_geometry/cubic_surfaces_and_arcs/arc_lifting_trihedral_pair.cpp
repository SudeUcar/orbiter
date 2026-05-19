// arc_lifting_trihedral_pair.cpp
// 
// Anton Betten, Fatma Karaoglu
//
// January 24, 2017
// moved here from clebsch.cpp: March 22, 2017
//
// 
//
//

#include "orbiter.h"

using namespace std;

namespace orbiter {
namespace layer5_applications {
namespace applications_in_algebraic_geometry {
namespace cubic_surfaces_and_arcs {


arc_lifting_trihedral_pair::arc_lifting_trihedral_pair()
{
	Record_birth();
	q = 0;
	F = NULL;
	Surf = NULL;
	Surf_A = NULL;


	arc = NULL;
	arc_size = 0;

	the_equation = NULL;

	Web = NULL;

	Trihedral_pair = NULL;

}

arc_lifting_trihedral_pair::~arc_lifting_trihedral_pair()
{
	Record_death();
	if (the_equation) {
		FREE_int(the_equation);
	}
	if (Web) {
		FREE_OBJECT(Web);
	}
	if (Trihedral_pair) {
		FREE_OBJECT(Trihedral_pair);
	}
}


void arc_lifting_trihedral_pair::create_surface_and_group(
		applications_in_algebraic_geometry::cubic_surfaces_in_general::surface_with_action *Surf_A,
	long int *Arc6, int verbose_level)
{
	int f_v = (verbose_level >= 1);

	if (f_v) {
		cout << "arc_lifting_trihedral_pair::create_surface_and_group" << endl;
	}



	arc_lifting_trihedral_pair::arc = Arc6;
	arc_lifting_trihedral_pair::arc_size = 6;
	arc_lifting_trihedral_pair::Surf_A = Surf_A;
	Surf = Surf_A->Surf;
	F = Surf->F;
	q = F->q;



	if (f_v) {
		cout << "arc_lifting_trihedral_pair::create_surface_and_group "
				"before create_web_of_cubic_curves" << endl;
	}
	create_web_of_cubic_curves(verbose_level - 2);
	if (f_v) {
		cout << "arc_lifting::create_surface_and_group "
				"after create_web_of_cubic_curves" << endl;
	}


	Trihedral_pair = NEW_OBJECT(trihedral_pair_with_action);


	if (f_v) {
		cout << "arc_lifting::create_surface_and_group "
				"before Trihedral_pair->init" << endl;
	}
	Trihedral_pair->init(this, verbose_level);
	if (f_v) {
		cout << "arc_lifting::create_surface_and_group "
				"after Trihedral_pair->init" << endl;
	}

	
	
	if (f_v) {
		cout << "arc_lifting::create_surface_and_group done" << endl;
	}
}


void arc_lifting_trihedral_pair::create_web_of_cubic_curves(
		int verbose_level)
{
	int f_v = (verbose_level >= 1);
	
	if (f_v) {
		cout << "arc_lifting_trihedral_pair::create_web_of_cubic_curves" << endl;
	}


	the_equation = NEW_int(20);
	

	Web = NEW_OBJECT(geometry::algebraic_geometry::web_of_cubic_curves);

	if (f_v) {
		cout << "arc_lifting_trihedral_pair::create_web_of_cubic_curves before Web->init" << endl;
	}
	Web->init(Surf, arc, verbose_level);
	if (f_v) {
		cout << "arc_lifting_trihedral_pair::create_web_of_cubic_curves after Web->init" << endl;
	}





	if (f_v) {
		cout << "arc_lifting_trihedral_pair::create_web_of_cubic_curves done" << endl;
	}
}




void arc_lifting_trihedral_pair::report(
		std::ostream &ost, int verbose_level)
{
	int f_v = (verbose_level >= 1);

	if (f_v) {
		cout << "arc_lifting_trihedral_pair::report" << endl;
	}


	if (f_v) {
		cout << "arc_lifting_trihedral_pair::report "
				"before Web->report" << endl;
	}
	Web->report(ost, verbose_level);
	if (f_v) {
		cout << "arc_lifting_trihedral_pair::report "
				"after Web->report" << endl;
	}

	if (f_v) {
		cout << "arc_lifting_trihedral_pair::report "
				"before Trihedral_pair->report" << endl;
	}
	Trihedral_pair->report(ost, verbose_level);
	if (f_v) {
		cout << "arc_lifting::report "
				"after Trihedral_pair->report" << endl;
	}


	if (f_v) {
		cout << "arc_lifting_trihedral_pair::report done" << endl;
	}
}


void arc_lifting_trihedral_pair::report_equation(
		std::ostream &ost)
{
	Surf_A->Surf->PolynomialDomains->print_equation_in_trihedral_form(
			ost,
				Trihedral_pair->The_six_plane_equations,
				Trihedral_pair->lambda,
				the_equation);
}








}}}}




