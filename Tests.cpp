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
#include "CustomException.h"

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

    v.add(d1);
    v.add(d2);
    v.add(d3);
    v.add(d4);
    v.add(d5);
    assert(v.get_dogs().size() == 5);

    try {
        v.add(d1);
        assert(false);
    } catch (OperationException& e) { }

    v.remove(d1);
    try {
        v.remove(d1);
        assert(false);
    } catch (OperationException& e) { }
    v.remove(d2);

    try {
        v.update(d1, d3);
        assert(false);
    } catch (OperationException& e) { }
    try {
        v.update(d3, d4);
        assert(false);
    } catch (OperationException& e) { }
    v.update(d3, d1);

    RepositoryUser w;
    w.set_list(v.get_dogs());
    assert(w.get_size_list() == 3);

    w.add_adoption(d3);
    std::vector<Dog> z = w.get_adopted();
    assert(z.size() == 1);
    assert(z[0].get_name() == "Hachi");

    assert(w.get_current().get_name() == "Rex");
    w.go_next();
    assert(w.get_current().get_name() == "Derek");
}

void Tests::test_controller() {
    RepositoryAdmin v;
    ControllerAdmin c{v};

    c.add(1, "Pitbull", "Rex", "link1");
    try {
        c.add(1, "Pitbull", "Rex", "link1");
        assert(false);
    } catch (OperationException& e) { }

    c.remove(1, "Pitbull", "Rex");
    try {
        c.remove(1, "Pitbull", "Rex");
        assert(false);
    } catch (OperationException& e) { }

    c.add(1, "Pitbull", "Rex", "link1");
    c.update(1, "Pitbull", "Rex", 2, "Husky", "Max", "link2");
    try {
        c.update(1, "Pitbull", "Rex", 2, "Husky", "Max", "link2");
        assert(false);
    } catch (OperationException& e) { }
}


