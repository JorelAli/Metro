#pragma once

#include "pch.h"

namespace git {

    class Index {
    public:
        explicit Index(git_index *index) : index(index) {};
        ~Index();

        void add_all(StrArray pathspec, unsigned int flags, MatchedPathCallback callback);
        OID write_tree();
        void write();
        ConflictIterator conflict_iterator();
        [[nodiscard]] int entrycount() const;

    private:
        git_index *index;
    };

}