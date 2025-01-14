int N = 1e5;
int BLOCK_SZ = sqrt(N);

struct Query {
  int l, r, idx;
  bool operator<(Query other) const {
    return make_pair(l / BLOCK_SZ, r) <
         make_pair(other.l / BLOCK_SZ, other.r);
  }
};

vector<int> solve(vector<Query> queries) {
  vector<int> answers(queries.size());
  sort(queries.begin(), queries.end());

  int currL = 0;
  int currR = -1;
  int currAns = 0;
  for (Query q : queries) {
    int L = q.l, R = q.r, idx = q.idx;
    while (currL > L) {
      currL--;
      // currAns += add(currL);
    }
    while (currR < R) {
      currR++;
      // currAns += add(currR);
    }
    while (currL < L) {
      // currAns -= remove(currL);
      currL++;
    }
    while (currR > R) {
      // currAns -= remove(currR);
      currR--;
    }
    answers[q.idx] = currAns;
  }
  return answers;
}