/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#include "Subject.h"
#include <algorithm>

Subject::~Subject() {
    //Never delete observers here because they are non-owning pointers (Composite tree)
    //just clear the list.
    observers.clear();
}

//if returns false, observer was already registered or null pointer
//if return true, observer was added to the list
bool Subject::attach(Observer* observer) {
    //make sure not storing nullpointer
    if (observer== 0) 
    {
        return false;
    }

    //check to see if pointer is already in the list
    if (std::find(observers.begin(), observers.end(), observer)!= observers.end()) {
        return false;
    }

    //add to the list
    observers.push_back(observer);
    return true;
}

//if returns false, observer was not registered
//if return true, observer was removed from the list
bool Subject::detach(Observer* observer) {
    // stores an iterator (erase can know where to remove from)
    std::vector<Observer*>::iterator it = std::find(observers.begin(), observers.end(), observer);

    if (it == observers.end()) {
        return false;
    }


    //detatch: remove single element it points at (points into observers)
    observers.erase(it);
    return true;
}


void Subject::notify(const Notice& notice) {
    //copies(pointer) whole observer vector
    std::vector<Observer*> snapshot = observers;

    for (std::size_t iCount = 0; iCount < snapshot.size(); ++iCount) {
        if (snapshot[iCount] != 0) {
            snapshot[iCount]->update(notice);
        }
    }
}

std::size_t Subject::observerCount() const {
    return observers.size();
}
