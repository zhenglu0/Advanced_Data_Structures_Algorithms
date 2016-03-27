/** @file hardFlograph.cpp
 *
 *  @author Jon Turner
 *  @date 2011
 *  This is open source software licensed under the Apache 2.0 license.
 *  See http://www.apache.org/licenses/LICENSE-2.0 for details.
 */

#include "Adt.h"
#include "Util.h"
#include "Flograph.h"

using namespace grafalgo;

/** Generate a flow graph that takes a long time to complete.
 *  The generated graphs are particularly hard for augmenting
 *  path algorithms that augment along shortest paths, and
 *  closely related algorithms, like Dinic's algorithm.
 * 
 *  @param k1 is a parameter that controls the number of distinct
 *  augmenting path lengths (aka phases)
 *  @param k2 is a parameter that controls both the number of phases
 *  and the time required for each augmenting path search
 *  @param fg is a reference to a flow graph in which the result
 *  is returned
 *  
 *  The generated graphs have 16*k1 + 2*k2 + 6 vertices and
 *  20*k1 + k2^2 + 4*k2 edges.
 */
void hardFlograph(int k1, int k2, Flograph& fg) {
	// determine first vertex in each group
	int c1 = 2;		// start of short chain from source
	int c2 = c1 + 4*k1;	// start of long chain from source
	int bl = c2 + 4*k1 + 2;	// start of 1st vertex group in bipartite graph
	int br = bl + k2;	// start of 2nd vertex group in bipartite graph
	int c3 = br + k2;	// start of long chain to sink
	int c4 = c3 + 4*k1 + 2;	// start of short chain to sink

	int n = c4 + 4*k1;
	int m = 20*k1 + k2*k2 + 4*k2;	

	fg.resize(n,m);
	fg.setSrc(1); fg.setSnk(n);

	// build short chain from source
	edge e;
	for (int i = 0; c1+i < c2-1; i++) {
		if ((i%4) == 0) { 
			e = fg.join(fg.src(),c1+i); fg.setCapacity(e,k2*k2);
		}
		e = fg.join(c1+i,c1+i+1); fg.setCapacity(e,k1*k2*k2);
	}
	// build long chain from source
	for (int i = 0; c2+i < bl-1; i++) {
		if ((i%4) == 0 && c2+i < bl-3) { 
			e = fg.join(fg.src(),c2+i); fg.setCapacity(e,k2*k2);
		}
		e = fg.join(c2+i,c2+i+1); fg.setCapacity(e,k1*k2*k2);
	}
	// connect source chains to bipartite graph
	for (int i = 0; i < k2; i++) {
		e = fg.join(c2-1,bl+i); fg.setCapacity(e,k1*k2); 
		e = fg.join(bl-1,br+i); fg.setCapacity(e,k1*k2);
	}
	// build central bipartite graph
	for (int i = 0; i < k2; i++) {
		for (int j = 0; j < k2; j++) {
			e = fg.join(bl+i, br+j); fg.setCapacity(e,1);
		}
	}
	// connect bipartite graph to sink chains
	for (int i = 0; i < k2; i++) {
		e = fg.join(bl+i,c3); fg.setCapacity(e,k1*k2); 
		e = fg.join(br+i,c4); fg.setCapacity(e,k1*k2);
	}
	// build long chain to sink
	for (int i = 0; c3+i < c4-1; i++) {
		if ((i%4) == 1 && i > 1) {
			e = fg.join(c3+i,fg.snk()); fg.setCapacity(e,k2*k2);
		}
		e = fg.join(c3+i,c3+i+1); fg.setCapacity(e,k1*k2*k2);
	}
	e = fg.join(c4-1,fg.snk()); fg.setCapacity(e,k2*k2);
	// build short chain to sink
	for (int i = 0; c4+i < n-1; i++) {
		if ((i%4) == 3) { 
			e = fg.join(c4+i,fg.snk()); fg.setCapacity(e,k2*k2);
		}
		e = fg.join(c4+i,c4+i+1); fg.setCapacity(e,k1*k2*k2);
	}
	e = fg.join(n-1,fg.snk()); fg.setCapacity(e,k2*k2);
}
