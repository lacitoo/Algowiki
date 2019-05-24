import sys

class State:
    def __init__(self, first, second):
        self.first = 0
        self.second = 0
        self.first_max = first
        self.second_max = second
        self.constuctor = 'none'
        self.prev = 'null'

    def __copy__(self):
        s = State(self.first_max, self.second_max)
        s.first = self.first
        s.second = self.second
        s.constuctor = self.constuctor
        s.prev = self.prev

        return s

    def __str__(self):
        return "State < fM: '{}', sM: '{}', f: '{}', s: '{}' >".format(self.first_max, self.second_max, self.first, self.second)

    def __hash__(self):
        return hash(self.__str__())

    def print_path(self):
        if(self.constuctor == 'none'):
            return
        else:
            self.prev.print_path()
            print(self.constuctor)
    
    def __eq__(self, other):
        return (self.first == other.first and
                self.first_max == other.first_max and
                self.second == other.second and
                self.second_max == other.second_max)

    def TA(self):
        s = self.__copy__()
        s.first = s.first_max
        s.constuctor = 'TA'
        s.prev = self
        return s

    def TB(self):
        s = self.__copy__()
        s.second = s.second_max
        s.constuctor = 'TB'
        s.prev = self
        return s

    def UA(self):
        s = self.__copy__()
        s.first = 0
        s.constuctor = 'UA'
        s.prev = self
        return s

    def UB(self):
        s = self.__copy__()
        s.second = 0
        s.constuctor = 'UB'
        s.prev = self
        return s

    def AB(self):
        s = self.__copy__()
        amount = s.first if s.first + s.second <= s.second_max else s.second_max - s.second
        s.first -= amount
        s.second += amount
        s.constuctor = 'AB'
        s.prev = self
        return s

    def BA(self):
        s = self.__copy__()
        amount = s.second if s.first + s.second <= s.first_max else s.first_max - s.first
        s.first += amount
        s.second -= amount
        s.constuctor = 'BA'
        s.prev = self
        return s

def gen_next_state(s: State, all_states: set):
    new_states = [s.TA(), s.TB(), s.UA(), s.UB(), s.AB(), s.BA()]
    returning_states = []

    for state in new_states:
        if state not in all_states:
            returning_states.append(state)
            all_states.add(state)

    return returning_states

def iterate(states, all_states):
    new_states = []
    for state in states:
        for s in gen_next_state(state, all_states):
            new_states.append(s)

    return new_states


if __name__ == "__main__":
    n = int(input())
    first, second = [int(x) for x in input().split(' ')]

    starting_state = State(first, second)
    all_states = set([starting_state])

    found = False
    new_s = [starting_state]
    counter = 0
    while not found:
        new_s = iterate(new_s, all_states)
        counter += 1

        if new_s == []:
            print("NINCS")
            found = True
            break

        for state in new_s:
            if state.second == n:
                print(counter)
                state.print_path()
                found = True
                break
