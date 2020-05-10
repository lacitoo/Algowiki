#include <iostream>
#include <vector>
#include <queue>

//#define DEBUG_MODE

struct Member {
    Member(int _id, int _parent, int _time) : id(_id), parent(_parent), time(_time) {}

    long int delay() {
        return maxtime + time;
    }

    int id, parent, time;
    long int maxtime = 0;
    std::vector<Member*> children;
};


class Company
{
public:
    Company(int _n, int _k) : n(_n), k(_k) {}

    ~Company() {
        for (int i = 0; i < members.size(); ++i) {
            delete members[i];
        } 
    }

    void addMember(int id, int parent, int time) {
        maxtime = (time > maxtime) ? time : maxtime;
        members.push_back(new Member(id, parent, time));
    }

    unsigned long long int solution() {
        linkChildren();
        bfs();

        #ifdef DEBUG_MODE
        for (int i = 0; i < membersInOrder.size(); ++i) {
            std::cout << membersInOrder[i]->id << " ";
        }
        std::cout << std::endl;
        #endif

        unsigned long long int min = 0, max = n * maxtime;
        while (min < max) {
            unsigned long long int guess = (min + max) / 2;
            if (isPossible(guess)) {
                max = guess;
            } else {
                min = guess + 1;
            }
        }
        return min;
    }
private:
    unsigned long long int n, k;
    unsigned long long int maxtime = 0;
    std::vector<Member*> members, membersInOrder;

    void linkChildren() {
        for (int i = 0; i < n; ++i) {
            int parent = members[i]->parent;
            if (parent != -1) {
                members[parent]->children.push_back(members[i]);
            }
        }
    }

    void bfs() {
        std::queue<Member*> q;
        q.push(members[0]);
        while (!q.empty()) {
            Member* i = q.front();
            q.pop();
            membersInOrder.push_back(i);
            for (int j = 0; j < i->children.size(); ++j) {
                q.push(i->children[j]);
            }
        }
    }

    bool isPossible(unsigned long long int maxdelay) {
        int numOfCuts = 0;
        for (int i = membersInOrder.size() - 1; i > 0; --i) {
            membersInOrder[i]->maxtime = 0;
            for (int j = 0; j < membersInOrder[i]->children.size(); ++j) {
                if (membersInOrder[i]->children[j]->delay() > membersInOrder[i]->maxtime) {
                    membersInOrder[i]->maxtime = membersInOrder[i]->children[j]->delay();
                }
            }
            if (membersInOrder[i]->delay() > maxdelay) {
                ++numOfCuts;
                membersInOrder[i]->maxtime = -(membersInOrder[i]->time);
            }
        }
        return numOfCuts <= k;
    }
};



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    Company c(n, k);
    c.addMember(0, -1, 0);
    for (int i = 1; i < n; ++i) {
        int parent, time;
        std::cin >> parent >> time;
        c.addMember(i, parent - 1, time);
    }

    std::cout << c.solution() << std::endl;

    return 0;
}