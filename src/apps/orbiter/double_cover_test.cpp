#include "orbiter.h"

using namespace std;
using namespace orbiter;

int main(int argc, char **argv) {
    layer5_applications::user_interface::core_system::orbiter_top_level_session Top_level_session;
    layer5_applications::user_interface::core_system::The_Orbiter_top_level_session = &Top_level_session;
    
    int verbose_level = 0;
    combinatorics::graph_theory::graph_theory_domain GT;
    
    combinatorics::graph_theory::colored_graph *CG = NEW_OBJECT(combinatorics::graph_theory::colored_graph);
    int n = 1;
    int *Adj = NEW_int(1 * 1);
    Adj[0] = 0; 
    int *colors = NEW_int(1);
    colors[0] = 0;
    string label = "Graph_0";
    string label_tex = "Graph\\_0";
    CG->init_adjacency(1, 1, 1, colors, Adj, label, label_tex, verbose_level);
    
    for (int i = 0; i <= 5; i++) {
        cout << "\n=============================================" << endl;
        cout << "Iteration " << i << ", Graph size: " << CG->nb_points << endl;
        cout << "=============================================" << endl;
        
        CG->properties(verbose_level);
        
        cout << "Eigenvalues:" << endl;
        GT.eigenvalues(CG, verbose_level);
        
        combinatorics::graph_theory::colored_graph *CG2 = CG->double_cover(verbose_level);
        FREE_OBJECT(CG);
        CG = CG2;
    }
    
    return 0;
}
