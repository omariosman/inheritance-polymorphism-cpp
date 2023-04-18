#include <iostream>
#include <vector>
#include <algorithm>
#include "DailyEvent.h"
#include "WeeklyEvent.h"
#include "FirstOccComparator.h"
#include "LastOccComparator.h"
#include "DescriptionComparator.h"
#include "Planner.h"
#include "Utilis.h"

using namespace std;

void printLastOccurences(Planner *p) {
    std::vector<AbstractEvent*> all_events = p->getEvents();
    
    for (int i = 0; i < p->size(); i++){
        cout << "Event: " << all_events[i]->getDescription() << "\t";
        cout << "Last occurrence: " << Utilis::timeToString(all_events[i]->lastOccurrence()) << "\n";
    }
 }

void displayRecurrencies(Planner *p, string eventName) {
    cout << "\nRecurrences of: " << eventName << endl;
    AbstractEvent* current_event = p->getEvent(eventName);
    if (current_event) {
        current_event->printAllRecurrences();
    } else {
        cout << current_event <<  " event not found.\n";
    }
}

int main() {
    Planner p(20);

    time_t input, start, end, limit;

    limit = Utilis::createTime(2023, 5, 25);

    start = Utilis::createTime(2023, 1, 3, 21, 10);
    end = Utilis::createTime(2023, 1, 3, 22, 30);
    p.addEvent(new WeeklyEvent("Shopping Time", start, end, limit));

    start = Utilis::createTime(2023, 3, 23, 18, 00);
    end = Utilis::createTime(2023, 3, 23, 19, 0);
    p.addEvent(new DailyEvent("Breakfast time", start, end, 10));

    start = Utilis::createTime(2023, 2, 5, 15, 30);
    end = Utilis::createTime(2023, 2, 5, 16, 45);
    p.addEvent(new WeeklyEvent("OOD SUN Lecture", start, end, limit));

    start = Utilis::createTime(2023, 1, 11, 10, 0);
    end = Utilis::createTime(2023, 1, 11, 11, 30);
    p.addEvent(new WeeklyEvent("CSCE 1521 Section B", start, end, limit));

    start = Utilis::createTime(2023, 2, 1, 15, 30);
    end = Utilis::createTime(2023, 2, 1, 16, 45);
    p.addEvent(new WeeklyEvent("OOD WED Lecture", start, end, limit));

    start = Utilis::createTime(2023, 1, 10, 11, 30);
    end = Utilis::createTime(2023, 1, 10, 13, 0);
    p.addEvent(new WeeklyEvent("CSCE 1521 Section A", start, end, limit));

    start = Utilis::createTime(2023, 1, 11, 14, 30);
    end = Utilis::createTime(2023, 1, 11, 17, 30);
    p.addEvent(new WeeklyEvent("CSCE 4321 Section A", start, end, limit));

    start = Utilis::createTime(2023, 2, 14, 14, 30);
    end = Utilis::createTime(2023, 2, 14, 17, 0);
    p.addEvent(new WeeklyEvent("TA Office Hours", start, end, limit));

    start = Utilis::createTime(2023, 4, 11, 9, 30);
    end = Utilis::createTime(2023, 4, 11, 17, 30);
    p.addEvent(new DailyEvent("Examination", start, end, 18));

    cout << "############################################################" << endl;

    //TODO: Display here the Recurrences of: OOD SUN Lecture
    string eventName = "OOD SUN Lecture";
    displayRecurrencies(&p, eventName);

    cout << "############################################################" << endl;
    cout << "############################################################" << endl;

    //TODO: Display here the Recurrences of: Breakfast time
    eventName = "Breakfast time";
    displayRecurrencies(&p, eventName);

    cout << "############################################################" << endl;
    cout << "############################################################" << endl;

    cout << "\nThe start time of last occurrence of all the events: " << endl;
    printLastOccurences(&p);

    cout << "############################################################" << endl;
    cout << "############################################################" << endl;

    cout << "\nEvents that have a recurrence on March 28, 2023:\n"; 
    //hasRecurenceOnDate(&p, Utilis::createTime(2023, 3, 28));
    p.display(Utilis::createTime(2023, 3, 28));

    cout << "############################################################" << endl;
    cout << "############################################################" << endl;

    p.addEvent(p.remove(0));

    cout << "############################################################" << endl;

    cout<<"Content of the Planner: " << endl; 

    cout << p.toString() << endl;

    cout << "############################################################" << endl;

    cout<<"Sorting the content of the Planner by first occurrence..." << endl;

    p.sort(FirstOccComparator());

    cout<<"Content of the Planner: " << endl; 

    cout << p.toString() << endl;

    cout << "############################################################" << endl;

    cout<<"Sorting the content of the Planner by last occurrence..." << endl;

    p.sort(LastOccComparator());

    cout<<"Content of the Planner: " << endl; 

    cout << p.toString() << endl;

    cout << "############################################################" << endl;

    cout<<"Sorting the content of the Planner by decription..." << endl;

    p.sort(DescriptionComparator());

    cout<<"Content of the Planner: " << endl; 

    cout << p.toString() << endl;
    
    cout << "############################################################" << endl;
    cout << "############################################################" << endl;

    return 0;
}

