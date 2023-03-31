#include "hellocmake/helloworld.hpp"

#include <fstream>

#include <CGAL/version_macros.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_2.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/draw_triangulation_2.h>


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_2<K> Triangulation;
typedef CGAL::Delaunay_triangulation_2<K> Delaunay;
typedef Triangulation::Point Point;
typedef Triangulation::Vertex_circulator Vertex_circulator;



int main() {
    helloworld("Nik");
	std::cout << "Hello CGAL! (version: " << CGAL_VERSION_MAJOR << "." << CGAL_VERSION_MINOR << ")\n" << std::endl;
	
	// Try out CGAL specific operations
	std::ifstream in("../data/triangulation_prog1.cin");  // new data points for testing can be simply added to the file manually
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

	CGAL::draw(dt);  // drawing requires CGAL_Qt5 
	
	return EXIT_SUCCESS;
}
