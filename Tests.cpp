//
// Created by alex on 20.03.2016.
//

#include <cassert>
#include <iostream>
#include "Tests.h"
#include "Vector.h"
#include "RepositoryAdmin.h"
#include "ControllerAdmin.h"
#include "RepositoryUser.h"

void Tests::run_tests() {
    test_vector();
    test_repository();
    test_controller();
}

void Tests::test_vector() {
    Vector<int> v(1);
    for (int i = 0; i < 10; i++)
        v.add(i);

    assert(v.size() == 10);
    for (int i = 0; i < 10; i++)
        assert(v[i] == i);

    for (int i = 0; i < 10; i++)
        assert(v.find(i) == i);

    Vector<int> w(v);
    assert(w.size() == 10);
    for (int i = 0; i < 10; i++)
        assert(w[i] == i);

    v.remove(5);
    assert(v.size() == 9);
    assert(v[5] == 6);
    assert(v[8] == 9);
}

void Tests::test_repository() {
    RepositoryAdmin v;
    Dog d1{1, "Pitbull", "Rex", "link1"};
    Dog d2{2, "Husky", "Max", "link2"};
    Dog d3{2, "Doge", "Hachi", "link3"};
    Dog d4{1, "Shepard", "Derek", "link4"};
    Dog d5{3, "Husky", "Min", "link5"};

    assert(v.add(d1) == 1);
    assert(v.add(d2) == 1);
    assert(v.add(d3) == 1);
    assert(v.add(d4) == 1);
    assert(v.add(d5) == 1);

    assert(v.add(d1) == 0);
    assert(v.remove(d1) == 1);
    assert(v.remove(d1) == 0);
    assert(v.remove(d2) == 1);

    assert(v.update(d1, d3) == -1);
    assert(v.update(d3, d4) == 0);
    assert(v.update(d3, d1) == 1);

    RepositoryUser w;
    w.set_list(v.get_dogs());
    assert(w.get_size_list() == 3);

    w.add_adoption(d3);
    Vector<Dog> z = w.get_adopted();
    assert(z.size() == 1);
    assert(z[0].get_name() == "Hachi");

    assert(w.get_current().get_name() == "Rex");
    w.go_next();
    assert(w.get_current().get_name() == "Derek");
}

void Tests::test_controller() {
    RepositoryAdmin v;
    ControllerAdmin c{v};

    assert(c.add(1, "Pitbull", "Rex", "link1") == 1);
    assert(c.add(1, "Pitbull", "Rex", "link1") == 0);
    assert(c.remove(1, "Pitbull", "Rex") == 1);
    assert(c.remove(1, "Pitbull", "Rex") == 0);

    assert(c.add(1, "Pitbull", "Rex", "link1") == 1);
    assert(c.update(1, "Pitbull", "Rex", 2, "Husky", "Max", "link2") == 1);
    assert(c.update(1, "Pitbull", "Rex", 2, "Husky", "Max", "link2") == -1);
}


