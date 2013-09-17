#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

#define INFILE "B-small-practice.in"
#define OUTFILE "B-small-practice.out"

double calculateTimeOfMinDistance (int xc, int yc, int zc, int vxc, int vyc, int vzc) {
	double numerator = xc*vxc + yc*vyc + zc*vzc;
	double denominator = vxc*vxc + vyc*vyc + vzc*vzc;
	double result = 0.0-numerator/denominator;
	if (result < 0.0) result = 0.0;
	return result;
}

double calculateMinDistance (double timeOfMinDistance, int n, int xc, int yc, int zc, int vxc, int vyc, int vzc) {
	double x = (xc+vxc*timeOfMinDistance)/n;
	x = x*x;
	double y = (yc+vyc*timeOfMinDistance)/n;
	y = y*y;
	double z = (zc+vzc*timeOfMinDistance)/n;
	z = z*z;
	return x+y+z;
}

int main (char *argv, int argc) {
	ifstream ifs(INFILE);
	ofstream ofs(OUTFILE);
	int testCases;
	ifs >> testCases;
	for (int testCase = 1; testCase <= testCases; testCase++) {
		
		int fireflies;
		ifs >> fireflies;
		double timeOfMinDistance, minDistance;
		int xc=0, yc=0, zc=0, vxc=0, vyc=0, vzc=0;
		for (int i=0; i<fireflies; i++) {
			int x, y, z, vx, vy, vz;
			ifs >> x >> y >> z >> vx >> vy >> vz;
			xc += x;
			yc += y;
			zc += z;
			vxc += vx;
			vyc += vy;
			vzc += vz;
		}
		timeOfMinDistance = calculateTimeOfMinDistance(xc, yc, zc, vxc, vyc, vzc);
		minDistance = calculateMinDistance(timeOfMinDistance, fireflies, xc, yc, zc, vxc, vyc, vzc);
		ofs << setiosflags(ios::fixed);
		ofs << "Case #" << testCase << ": " << setprecision (8) << minDistance << " " << setprecision (8) << timeOfMinDistance << endl;
	}
	return 0;
}