#include <iostream>

using namespace std;

void main() {

    double e_value = 2.7182818284;
    double X = 20037508.34;

    double lat3857, long3857;

    cin >> lat3857 >> long3857;
    //converting the longitute from epsg 3857 to 4326
    double long4326 = (long3857 * 180) / X;

    //converting the latitude from epsg 3857 to 4326 split in multiple lines for readability        
    double lat4326 = lat3857 / (X / 180);
    double exponent = (3.141592 / 180) * lat4326;

    lat4326 = atan(pow(e_value, exponent));
    lat4326 = lat4326 / (3.141592 / 360); // Here is the fixed line
    lat4326 = lat4326 - 90;
    cout << lat4326 << ' ' << long4326;
    exit(0);
}