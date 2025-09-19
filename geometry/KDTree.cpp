// KD-tree for 2D points
// - nearest neighbor search
// - farthest point search
// O(N log N) build, O(log N) query
// Reference: Kctl (nearest) & Tweaked with ChatGpt for farthest point
// Farthest is stress tested against brute force

#include "Point.hpp"

typedef Point P;

const double INF = 1e18;

bool on_x(const P& a, const P& b) { return a.x < b.x; }
bool on_y(const P& a, const P& b) { return a.y < b.y; }

struct Node {
  typedef double T;
  P pt; 
  T x0 = INF, x1 = -INF, y0 = INF, y1 = -INF;
  Node *first = 0, *second = 0;

  T distance(const P& p) { 
  T x = (p.x < x0 ? x0 : p.x > x1 ? x1 : p.x);
  T y = (p.y < y0 ? y0 : p.y > y1 ? y1 : p.y);
  return (P(x,y) - p).dist2();
  }

  T maxDistance(const P& p) {
  T dx = max(abs(p.x - x0), abs(p.x - x1));
  T dy = max(abs(p.y - y0), abs(p.y - y1));
  return dx*dx + dy*dy;
  }

  Node(vector<P>&& vp) : pt(vp[0]) {
  for (P p : vp) {
    x0 = min(x0, p.x); x1 = max(x1, p.x);
    y0 = min(y0, p.y); y1 = max(y1, p.y);
  }
  if (vp.size() > 1) {
    sort(ALL(vp), x1 - x0 >= y1 - y0 ? on_x : on_y);
    int half = SZ(vp)/2;
    first = new Node({vp.begin(), vp.begin() + half});
    second = new Node({vp.begin() + half, vp.end()});
  }
  }
};

struct KDTree {
  typedef double T;
  Node* root;
  KDTree(const vector<P>& vp) : root(new Node({ALL(vp)})) {}

  pair<T, P> search(Node *node, const P& p) {
  if (!node->first)
    return {(p - node->pt).dist2(), node->pt};

  Node *f = node->first, *s = node->second;
  T bfirst = f->distance(p), bsec = s->distance(p);
  if (bfirst > bsec) swap(bsec, bfirst), swap(f, s);

  auto best = search(f, p);
  if (bsec < best.first)
    best = min(best, search(s, p));
  return best;
  }

  pair<T, P> nearest(const P& p) { return search(root, p); }

  pair<T, P> searchFarthest(Node *node, const P& p) {
  if (!node->first)
    return {(p - node->pt).dist2(), node->pt};

  Node *f = node->first, *s = node->second;
  T bfirst = f->maxDistance(p), bsec = s->maxDistance(p);
  if (bfirst < bsec) swap(bsec, bfirst), swap(f, s); // search larger side first

  auto best = searchFarthest(f, p);
  if (bsec > best.first)
    best = max(best, searchFarthest(s, p));
  return best;
  }

  pair<T, P> farthest(const P& p) { return searchFarthest(root, p); }
};
