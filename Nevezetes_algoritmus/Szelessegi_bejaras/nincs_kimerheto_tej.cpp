#include <vector>
#include <set>
#include <iostream>

class State
{
public:
    size_t* curr;
    size_t* max;
    State(int first, int second, int third)
    {
        curr = new size_t[4];
        max = new size_t[4];
        curr[0] = first;
        curr[1] = 0;
        curr[2] = 0;
        curr[3] = 0;
        max[0] = first;
        max[1] = second;
        max[2] = third;
        max[3] = 100;
    }

    State copy() const
    {
        State s(max[0], max[1], max[2]);
        s.curr[0] = curr[0];
        s.curr[1] = curr[1];
        s.curr[2] = curr[2];
        s.curr[3] = curr[3];

        return s;
    }

    friend std::ostream& operator<<(std::ostream& os, const State& s)
    {
        os << "State < max: { "<<s.max[0]<<", "<<s.max[1]<<", "<<s.max[2]<<", "<< s.max[3]<<"}, curr: {"
           <<s.curr[0]<<", "<<s.curr[1]<<", "<<s.curr[2]<<", "<< s.curr[3]<<"} >";
           return os;
    }

    friend bool operator==(const State& lhs, const State& rhs)
    {
        return (
            lhs.curr[0] == rhs.curr[0] &&
            lhs.curr[1] == rhs.curr[1] &&
            lhs.curr[2] == rhs.curr[2] &&
            lhs.curr[3] == rhs.curr[3] &&
            lhs.max[0] == rhs.max[0] &&
            lhs.max[1] == rhs.max[1] &&
            lhs.max[2] == rhs.max[2] &&
            lhs.max[3] == rhs.max[3]
        );
    }

    size_t hash() const
    {
        return (10000 * curr[0] + 1000 * curr[1] + 100 * curr[2] + 1 * curr[3]) + 100 * (10000 * max[0] + 100 * max[1] + max[2]);
    }

    friend bool operator<(const State& lhs, const State& rhs)
    {
        return (
            lhs.hash() < rhs.hash()
        );
    }


    State pour(size_t a, size_t b) const
    {

        State s = this->copy();
        size_t amount =  (s.curr[a] + s.curr[b] <= s.max[b]) ? s.curr[a] : s.max[b] - s.curr[b];
        s.curr[a] -= amount;
        s.curr[b] += amount;
        return s;
    }
};

std::vector<State> gen_next_state(const State& s, std::set<State>& all_states)
{
    std::vector<State> new_states = std::vector<State>{ s.pour(0,1), s.pour(0,2), s.pour(0,3),        s.pour(1,0), s.pour(1,2), s.pour(1,3),        s.pour(2,0), s.pour(2,1), s.pour(2,3),        s.pour(3,0), s.pour(3,1), s.pour(3,2),
    };

    std::vector<State> returning_states;

    for(size_t i = 0; i < 12; ++i)
    {
        const auto& found = all_states.find(new_states[i]);
        if(found == all_states.end())
        {
            all_states.insert(new_states[i]);
            returning_states.push_back(new_states[i]);
        }
    }

    return returning_states;
}

void iterate(std::vector<State>& states, std::set<State>& all_states)
{
    std::vector<State> new_states;

    for(State state : states)
    {
        for(State s : gen_next_state(state, all_states))
            new_states.push_back(s);
    }

    states = new_states;
}

int main()
{
    size_t first, second, third;
    std::cin >> first >> second >> third;

    State starting_state(first, second, third);

    std::set<State> all_states;
    all_states.insert(starting_state);

    std::vector<State> new_s;
    new_s.push_back(starting_state);

    while(true)
    {
        iterate(new_s, all_states);

        if(new_s.size() == 0)
            break;
    }

    std::set<size_t> solutions;
    for(State state : all_states)
        solutions.insert(state.curr[3]);

    std::vector<size_t> not_achivable;
    for(size_t i = 0; i <= first; ++i)
    {
        auto found = solutions.find(i);
        if(found == solutions.end())
        {
            not_achivable.push_back(i);
        }
    }

    std::cout << not_achivable.size() << std::endl;
    for(size_t i : not_achivable) std::cout << i << " ";

    return 0;
}
