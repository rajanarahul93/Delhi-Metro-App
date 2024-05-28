#include "Graph.h"
#include <iostream>
#include <string>
#include <climits> // Include this header to avoid "undefined INT_MAX"

void showMenu() {
    std::cout << "\n\t\t\t\t Delhi Metro Route Simulator" << std::endl;
    std::cout << "\t\t-------------------------------------------------------------------" << std::endl;
    std::cout << "\t\t1. List all the stations in the map" << std::endl;
    std::cout << "\t\t2. Show the Metro map" << std::endl;
    std::cout << "\t\t3. Get the distance between two stations" << std::endl;
    std::cout << "\t\t4. Get the minimum distance route from a station to another" << std::endl;
    std::cout << "\t\t5. Get the minimum time route from a station to another" << std::endl;
    std::cout << "\t\t6. Exit the simulator" << std::endl;
    std::cout << "\t\t-------------------------------------------------------------------" << std::endl;
    std::cout << "\t\tEnter your choice: ";
}

int main() {
    Graph g;

    // Adding stations
    g.addVertex("Punjabi Bagh West");
    g.addVertex("Netaji Subhash Place");
    g.addVertex("Azadpur");
    g.addVertex("Shahdara");
    g.addVertex("Kashmere Gate");
    g.addVertex("Chandni Chowk");
    g.addVertex("Janak Puri East");
    g.addVertex("New Delhi");
    g.addVertex("AIIMS");
    g.addVertex("Rajiv Chowk");
    g.addVertex("Yamuna Bank");
    g.addVertex("Jhangirpuri");
    g.addVertex("Botanical Garden");
    g.addVertex("Noida Sector 62");
    g.addVertex("Vaishali");
    g.addVertex("Moti Nagar");
    g.addVertex("Janak Puri West");
    g.addVertex("Dilshad Garden");
    g.addVertex("Dwarka Sector 21");
    g.addVertex("Huda City Center");
    g.addVertex("Saket");

    // Adding edges
    g.addEdge("Punjabi Bagh West", "Moti Nagar", 7);
    g.addEdge("Punjabi Bagh West", "Netaji Subhash Place", 3);
    g.addEdge("Netaji Subhash Place", "Azadpur", 4);
    g.addEdge("Azadpur", "Jhangirpuri", 7);
    g.addEdge("Shahdara", "Dilshad Garden", 4);
    g.addEdge("Shahdara", "Kashmere Gate", 8);
    g.addEdge("Kashmere Gate", "Chandni Chowk", 3);
    g.addEdge("Chandni Chowk", "New Delhi", 2);
    g.addEdge("Janak Puri East", "Janak Puri West", 1);
    g.addEdge("New Delhi", "Rajiv Chowk", 1);
    g.addEdge("AIIMS", "Rajiv Chowk", 7);
    g.addEdge("Rajiv Chowk", "Yamuna Bank", 6);
    g.addEdge("Rajiv Chowk", "Moti Nagar", 9);
    g.addEdge("Yamuna Bank", "Vaishali", 8);
    g.addEdge("Yamuna Bank", "Botanical Garden", 10);
    g.addEdge("Botanical Garden", "Noida Sector 62", 8);
    g.addEdge("Botanical Garden", "Dwarka Sector 21", 20);
    g.addEdge("Moti Nagar", "Janak Puri West", 7);
    g.addEdge("Dwarka Sector 21", "Janak Puri West", 10);
    g.addEdge("Huda City Center", "Saket", 15);
    g.addEdge("Saket", "AIIMS", 5);

    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 1) {
            g.displayStations();
        } else if (choice == 2) {
            g.displayMap();
        } else if (choice == 3) {
            std::string src, dest;
            std::cout << "\n\t\tEnter the source station: ";
            std::cin.ignore();
            std::getline(std::cin, src);
            std::cout << "\n\t\tEnter the destination station: ";
            std::getline(std::cin, dest);
            int distance = g.getMinimumDistance(src, dest);
            if (distance != INT_MAX) {
                std::cout << "\n\t\tMinimum distance from " << src << " to " << dest << " is " << distance << " units." << std::endl;
            } else {
                std::cout << "\n\t\tNo path exists between " << src << " and " << dest << "." << std::endl;
            }
        } else if (choice == 4) {
            std::string src, dest;
            std::cout << "\n\t\tEnter the source station: ";
            std::cin.ignore();
            std::getline(std::cin, src);
            std::cout << "\n\t\tEnter the destination station: ";
            std::getline(std::cin, dest);
            int distance = g.getMinimumDistance(src, dest);
            if (distance != INT_MAX) {
                std::cout << "\n\t\tMinimum distance path from " << src << " to " << dest << " is " << distance << " units." << std::endl;
            } else {
                std::cout << "\n\t\tNo path exists between " << src << " and " << dest << "." << std::endl;
            }
        } else if (choice == 5) {
            std::string src, dest;
            std::cout << "\n\t\tEnter the source station: ";
            std::cin.ignore();
            std::getline(std::cin, src);
            std::cout << "\n\t\tEnter the destination station: ";
            std::getline(std::cin, dest);
            int time = g.getMinimumTime(src, dest);
            if (time != INT_MAX) {
                std::cout << "\n\t\tMinimum time path from " << src << " to " << dest << " is " << time << " units." << std::endl;
            } else {
                std::cout << "\n\t\tNo path exists between " << src << " and " << dest << "." << std::endl;
            }
        } else if (choice == 6) {
            break;
        } else {
            std::cout << "\n\t\tInvalid choice! Please try again." << std::endl;
        }
    }

    return 0;
}
