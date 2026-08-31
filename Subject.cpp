#include "Subject.h"
#include <algorithm>

Subject::~Subject() {
    // Non-owning registrations only. Never delete observers here.
    observers.clear();
}

bool Subject::attach(Observer* observer) {
    if (observer == 0) {
        return false;
    }

    if (std::find(observers.begin(), observers.end(), observer) != observers.end()) {
        return false;
    }

    observers.push_back(observer);
    return true;
}

bool Subject::detach(Observer* observer) {
    std::vector<Observer*>::iterator it =
        std::find(observers.begin(), observers.end(), observer);

    if (it == observers.end()) {
        return false;
    }

    observers.erase(it);
    return true;
}

void Subject::notify(const Notice& notice) {
    // Snapshot policy: changes to registration during notification take effect
    // on the next notification cycle.
    std::vector<Observer*> snapshot = observers;

    for (std::size_t i = 0; i < snapshot.size(); ++i) {
        if (snapshot[i] != 0) {
            snapshot[i]->update(notice);
        }
    }
}

std::size_t Subject::observerCount() const {
    return observers.size();
}
