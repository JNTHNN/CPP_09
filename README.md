# Module CPP 09

Le module 09 est l'apogée de la piscine C++ ! Il demande une maîtrise totale de la **STL** (Standard Template Library) afin de résoudre des problèmes algorithmiques complexes et de traiter des données de manière efficace en choisissant le bon conteneur pour le bon usage.

## 1. Bourse au Bitcoin (`ex00`)
L'exercice **BitcoinExchange** demande de croiser une base de données CSV historique avec une liste de requêtes contenant des dates et des quantités.
- L'utilisation de `std::map` (dictionnaire) est incontournable ici pour associer une date unique (la clé) au taux de change (la valeur). La complexité de recherche est très performante.
- L'astuce majeure repose sur la méthode `lower_bound()` qui permet, si la date demandée n'existe pas dans la base, de retrouver la date la plus proche *inférieure ou égale* comme exigé par le sujet.

## 2. Notation Polonaise Inverse (`ex01`)
L'exercice **RPN** (Reverse Polish Notation) consiste à évaluer une expression mathématique où les opérateurs se trouvent après leurs opérandes (ex: `"3 4 +"` au lieu de `"3 + 4"`).
- L'usage de `std::stack` (une pile de type LIFO, Last In First Out) est absolument taillé pour la RPN. On empile les chiffres quand on les rencontre, et lorsqu'on croise un opérateur, on dépile les deux derniers nombres pour effectuer l'opération, puis on empile le résultat !
- Les erreurs de syntaxe (lettre inconnue, format invalide, espace manquant) et les divisions par zéro sont gérées via des exceptions propres pour stopper directement le programme.

## 3. L'algorithme de Ford-Johnson (`ex02`)
Le **PmergeMe** est de loin le plus grand défi de la piscine. Il faut coder l'algorithme de tri de Ford-Johnson (Merge-Insert Sort), un tri hybride complexe.
- L'algorithme découpe le tri en paires, trie les plus grands éléments, génère la suite de **Jacobsthal**, puis insère les petits éléments par recherche dichotomique pour minimiser drastiquement le nombre de comparaisons.
- Le sujet impose de faire cet algorithme **deux fois**, dans deux conteneurs différents (`std::vector` et `std::deque` ici), et de chronométrer l'exécution en mesurant la différence de performance d'allocation et de cache entre un tableau contigu et un tableau segmenté.

## Modifications Apportées
- Dans `RPN` (ex01), correction d'un bug majeur qui omettait les caractères invalides (ex: lettres) sans lancer d'erreur.
- Ajout d'une protection sécurisée empêchant de crasher misérablement l'exécution lors d'une division par zéro. L'exception coupe proprement le programme.
