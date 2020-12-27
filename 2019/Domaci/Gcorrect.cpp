#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int MAXN = 1e5;

int n, m, t;
vector<int> graf[MAXN];
int komponenta[MAXN], lowlink[MAXN];
stack<int> zasobnik;
int komponenta_ted, index;
bool v_zasobniku[MAXN];
vector<int> dag[MAXN];
int vaha[MAXN], vstupni_stupen[MAXN], nejdelsi[MAXN];
queue<int> fronta;

void reset() {
  for (int i = 1; i <= n; i++) {
    graf[i].clear();
    dag[i].clear();
    nejdelsi[i] = 0;
    lowlink[i] = n;
    vaha[i] = 0;
    v_zasobniku[i] = 0;
    vstupni_stupen[i] = 0;
  }
  komponenta_ted = 1;
  index = 0;
}

void dfs(int v) {
  lowlink[v] = index;
  int l = index;
  index++;
  zasobnik.push(v);
  v_zasobniku[v] = true;
  for (int i = 0; i < graf[v].size(); i++) {
    if (lowlink[graf[v][i]] == n)
      dfs(graf[v][i]);
    if (v_zasobniku[graf[v][i]])
      lowlink[v] = min(lowlink[v], lowlink[graf[v][i]]);
  }
  if (lowlink[v] == l) {
    while (v_zasobniku[v]) {
      v_zasobniku[zasobnik.top()] = false;
      komponenta[zasobnik.top()] = komponenta_ted;
      zasobnik.pop();
      vaha[komponenta_ted]++;
    }
    komponenta_ted++;
  }
}

void tarjan() {
  for (int i = 1; i <= n; i++)
    if (lowlink[i] == n)
      dfs(i);

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < graf[i].size(); j++) {
      if (komponenta[i] != komponenta[graf[i][j]]) {
        dag[komponenta[i]].push_back(komponenta[graf[i][j]]);
        vstupni_stupen[komponenta[graf[i][j]]]++;
      }
    }
  }
}

void vyres() {
  cin >> n >> m;
  reset();
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    graf[a].push_back(b);
  }
  tarjan();
  for (int i = 1; i < komponenta_ted; i++) {
    if (vstupni_stupen[i] == 0) {
      fronta.push(i);
      nejdelsi[i] = vaha[i];
    }
  }
  int vysledek = 0;
  while (!fronta.empty()) {
    int v = fronta.front();
    fronta.pop();
    vysledek = max(vysledek, nejdelsi[v]);
    for (int i = 0; i < dag[v].size(); i++) {
      nejdelsi[dag[v][i]] =
          max(nejdelsi[dag[v][i]], nejdelsi[v] + vaha[dag[v][i]]);
      vstupni_stupen[dag[v][i]]--;
      if (vstupni_stupen[dag[v][i]] == 0)
        fronta.push(dag[v][i]);
    }
  }
  cout << vysledek << endl;
}

int main() {
  cin >> t;
  while (t--)
    vyres();
  return 0;
}

