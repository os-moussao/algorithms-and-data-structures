// CP Algorithms template
void remove(idx);  // TODO: remove value at idx from data structure
void add(idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

////////////////////////////////////////////////////////
// CP Algorithms template tweaked as nested functions //
////////////////////////////////////////////////////////
int N = 1e5 + 10;
int block_size = sqrt(N);

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const
    {
        return make_tuple(l / block_size, r) <
              make_tuple(other.l / block_size, other.r);
    }
};

// my usual solve function
void solve() {
  int n, q; cin >> n >> q;
  
  // TODO: remove value at idx from data structure
  function<int(int)> remove = [&](int idx) {
    return 1;
  };

  // TODO: add value at idx from data structure
  function<int(int)> add = [&](int idx) {
    return 1;
  };

  // TODO: extract the current answer of the data structure
  function<int(void)> get_answer = [&]() {
    return 1;
  };

  // int block_size = sqrt(n);
  vector<Query> queries(q);
  vector<int> answers(queries.size());


  function<void(void)> mo_s_algorithm = [&]() {
      sort(queries.begin(), queries.end());

      // TODO: initialize data structure

      int cur_l = 0;
      int cur_r = -1;
      // invariant: data structure will always reflect the range [cur_l, cur_r]
      for (Query q : queries) {
          while (cur_l > q.l) {
              cur_l--;
              add(cur_l);
          }
          while (cur_r < q.r) {
              cur_r++;
              add(cur_r);
          }
          while (cur_l < q.l) {
              remove(cur_l);
              cur_l++;
          }
          while (cur_r > q.r) {
              remove(cur_r);
              cur_r--;
          }
          answers[q.idx] = get_answer();
      }
  };
}
