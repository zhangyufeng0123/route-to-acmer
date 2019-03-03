#include<bits/stdc++.h>

const double pi(3.1415926525);

using namespace std;

int main(void) {
    double x1, x2, y1, y2, z1, z2, r1, r2;
    long double v;
    cin >> x1 >> y1 >> z1 >> r1;
    cin >> x2 >> y2 >> z2 >> r2;
    long double va = 4 / 3 * pi * r1 * r1 * r1, vb = 4 / 3 * pi * r2 * r2 * r2;
    double len = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
    if (len >= r1 + r2) {
        v = 4.0 * pi / 3 * (r1 * r1 * r1 + r2 * r2 * r2);
    } else if (max(r1, r2) >= min(r1, r2) + len) {
        double r = max(r1, r2);
        v = 4.0 * pi / 3 * r * r * r;
    } else {
//        long double hb = r2 - (len * len + r2 * r2 - r1 * r1) / 2.0 * len;
//        long double hc = r1 - (len * len + r1 * r1 - r2 * r2) / 2.0 * len;
//        v = 4.0 * pi / 3 * (r1 * r1 * r1 + r2 * r2 * r2) - pi * hb * hb * (r2 - hb / 3.0) -
//            pi * hc * hc * (r1 - hc / 3.0);
//        long double ha = r1 - (((r1 * r1) - (r2 * r2) + (len * len)) / (2 * len));
//        long double hb = r2 - (((r2 * r2) - (r1 * r1) + (len * len)) / (2 * len));
//        long double vra = (pi * ha * ha * (3 * r1 - ha)) / 3.0;
//        long double vrb = (pi * hb * hb * (3 * r2 - hb)) / 3.0;
//        v = va + vb - vra - vrb;
        long double ha = r1 - ( ( (r1*r1) - (r2*r2) + (len*len) ) / (2*len) ); //球冠的高
        long double hb = r2 - ( ( (r2*r2) - (r1*r1) + (len*len) ) / (2*len) );

        long double vra = ( pi*ha*ha*( 3*r1-ha  ) ) / 3.0;     //球冠体积
        long double vrb = ( pi*hb*hb*( 3*r2-hb  ) ) / 3.0;

        v = 4.0 * pi / 3 * (r1 * r1 * r1 + r2 * r2 * r2) - vra - vrb;
    }
    cout << fixed << setprecision(7) << v << endl;
}