#include <fstream>
#include <vector>
#include <cassert>

#include <CGAL/version_macros.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_2.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/draw_triangulation_2.h>
#include <CGAL/Delaunay_triangulation_3.h>
#include <CGAL/point_generators_3.h>
#include <CGAL/draw_triangulation_3.h>
#include <CGAL/Triangulation.h>
#include <CGAL/Triangulation_data_structure.h>

// DATA
const char* tri_prog_1 = "../data/triangulation_prog1.cin"; 


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

typedef CGAL::Triangulation_2<K> Triangulation;
typedef CGAL::Delaunay_triangulation_2<K> Delaunay;

typedef CGAL::Delaunay_triangulation_3<K> DT3;
typedef CGAL::Creator_uniform_3<double, K::Point_3> Creator;

typedef Triangulation::Point Point;
typedef Triangulation::Edge_iterator  Edge_iterator;
typedef Triangulation::Vertex_circulator Vertex_circulator;


void test_delaunay_2D(bool with_qt);
void test_delaunay_3D(bool with_qt);
void test_delaunay_dD();


int main() {
	std::cout << "Hello CGAL! (version: " << CGAL_VERSION_MAJOR << "." << CGAL_VERSION_MINOR << ")\n" << std::endl;
	
	// Try out CGAL specific operations
	//test_delaunay_dD();
	test_delaunay_3D(true);
	//test_delaunay_2D(true);	 
	
	return EXIT_SUCCESS;
}

void test_delaunay_2D(bool with_qt = false) {
	std::ifstream in(tri_prog_1);  // new data points for testing can be simply added to the file manually
	std::istream_iterator<Point> begin(in);
	std::istream_iterator<Point> end;

	Delaunay dt;
	dt.insert(begin, end);  // this computes the triangulation

	std::cout << "The points on the convex hull of the triangulation are:\n";
	Vertex_circulator vc = dt.incident_vertices(dt.infinite_vertex()),
		done(vc);
	
	if (vc != nullptr) {
		do {
			std::cout << '\t' << vc->point() << std::endl;
		} while (++vc != done);
	}
	std::cout << std::endl;

	if (with_qt) {
		CGAL::draw(dt);  // drawing requires CGAL_Qt5
	}
}


void test_delaunay_3D(bool with_qt = false) {
	std::vector<K::Point_3> points;
	
	CGAL::Random_points_in_sphere_3<K::Point_3,Creator> g(1.0);
	
	std::copy_n(g, 50, std::back_inserter(points));
	
	DT3 dt3(points.begin(), points.end());
	
	if (with_qt) {
	  CGAL::draw(dt3);
	}
}


void test_delaunay_dD() {
	typedef CGAL::Triangulation_data_structure<CGAL::Dimension_tag<7> > TDS;
	TDS S;
	assert( 7 == S.maximal_dimension() );
  	assert( -2 == S.current_dimension() );
  	assert( S.is_valid() );

	std::vector<TDS::Vertex_handle> V(10);
	V[0] = S.insert_increase_dimension();  // insert first vertex
	assert(-1 == S.current_dimension());

	for(int i = 1; i <= 5; ++i) {
		V[i] = S.insert_increase_dimension(V[0]);
	}
	// the first 6 vertices have created a triangulation
	// of the 4-dim topological sphere
	// i.e. the boundary of 5-dim simplex
	assert(4 == S.current_dimension());
	assert(6 == S.number_of_vertices());
	assert(6 == S.number_of_full_cells());

	TDS::Full_cell_handle c = V[5]->full_cell();
	V[6] = S.insert_in_full_cell(c);
	// full cell c is split in 5
	assert(7 == S.number_of_vertices());
	assert(10 == S.number_of_full_cells());

	c = V[3]->full_cell();
	TDS::Facet ft(c, 2);  // the facet opposite to vertex 2 in c
	V[7] = S.insert_in_facet(ft);
	// facet is split in 4 and the two incident cells are split accordingly
	assert(8 == S.number_of_vertices());
	assert(16 == S.number_of_full_cells());

	c = V[3]->full_cell();
	TDS::Face face(c);
	// meant to contain the edge joining vertices 2 and 4 of full_cell c
	face.set_index(0, 2);  // namely vertex 2
	face.set_index(1, 4);  // namely vertex 4
	V[8] = S.insert_in_face(face);
	// face is split in two and all incident full_cells too
	assert(S.is_valid());

	TDS::Full_cell_handle hole[2];
	hole[0] = V[8]->full_cell();
	hole[1] = hole[0]->neighbor(0);
	// the hole is made of two adjacent full_cells
	ft = TDS::Facet(hole[0], 1);  // a face on the boundary of hole[0]
	V[9] = S.insert_in_hole(hole, hole+2, ft);
	// the hole is triangulated by linking a new vertex to its boundary
	assert(S.is_valid());
}
