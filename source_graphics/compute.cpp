#include "compute.hpp"
#include "draw.hpp"
double abs2(valarray<double> arr1) {
    double sum = 0;
    for (unsigned int i = 0; i < size(arr1); i++) {
        sum += pow(arr1[i], 2);
    }
    return(sqrt(sum));
}
valarray<double> gravity(valarray<double> pos1,
    valarray<double> pos2, double mass1, double mass2) {
    const double G = 6.6743015e-11;
    valarray<double> d = { pos1 - pos2 };
    double d_abs = abs2(d);
    return(-G * (mass1 * mass2) / pow(d_abs, 2) * (d) / d_abs);

}
void calc_gravity(planet &obj1, planet &obj2) {
    valarray<double> force = gravity(obj1.pos, obj2.pos, obj1.mass, obj2.mass);
    obj1.force += force;
    obj2.force += -force;
}
void calc(vector<planet> objects)
{
	int windowheight = 1280;
	int windowidth = 720;
    string step_string;
    cout << "Step (s): ";
    cin >> step_string;
    double step = stod(step_string);
    string scale_string;
    cout << "Scale: ";
    cin >> scale_string;
    double scale = stod(scale_string);
    string rot;
    cout << "Rotx: ";
    cin >> rot;
    double rotx = stod(rot);
    cout << "Roty: ";
    cin >> rot;
    double roty = stod(rot);
    cout << "Rotz: ";
    cin >> rot;
    double rotz = stod(rot);
    sf::RenderWindow window(sf::VideoMode(windowheight, windowidth), "Graph");
    window.clear(sf::Color::Black);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
	
        int b = 1;
        for (unsigned int x = 1; x < size(objects); x++) {
            for (int y = 0; y < b; y++) {
                calc_gravity(objects[x], objects[y]);
            }
            b++;
        }
        for (unsigned int i = 0; i < size(objects); i++) {
        	valarray<double> old_t_pos=transform3d(objects[i].pos,scale,rotx,roty,rotz);
        	sf::Vector2f old_pos(old_t_pos[0]+windowheight/2, -(old_t_pos[1]-windowidth/2));
            objects[i].calc_pos(step);
            valarray<double> t_pos=transform3d(objects[i].pos,scale,rotx,roty,rotz);
        	sf::Vector2f pos(t_pos[0]+windowheight/2, -(t_pos[1]-windowidth/2));
        	sf::Vertex line[] =
			{
    		sf::Vertex(old_pos),
    		sf::Vertex(pos)
			};
			window.draw(line, 2, sf::Lines);
        }
        
        window.display();
   }
}

