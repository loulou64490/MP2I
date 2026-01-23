(* somme des éléments de l *)
let rec somme (l:int list) : int =
  match l with
  | [] -> 0
  | a :: q -> a + somme q

(* true si x dans l, false sinon *)
let rec recherche (l: 'a list) (x: 'a) : bool =
  match l with
  | [] -> false
  | a::q -> if x=a then true else recherche q x

let rec concatener (l1: 'a list) (l2:'a list) : ('a list) =
  match l1 with
  | [] -> l2
  | a::l1' -> a::concatener l1' l2

let rec multi_concat (l:'a list list) : ('a list) =
  match l with 
  | l'::[] -> l'
  | a::b::l' -> multi_concat (concatener a b :: l')
  | [] -> []


let rec concatener2 (l1: 'a list) (l2:'a list) =
  match l1 with
  | [] -> l2
  | t::l1' -> concatener l1' (t::l2)

let test_somme () =
  assert (somme ([1;2;3]) = 6)

let test_recherche () =
  assert (recherche ([1;2;3]) 2)

let test_concatener () =
  assert (concatener ([1;2;3]) [4;5] = [1;2;3;4;5])

let test_multi_concat ()=
  assert (multi_concat [[1;2;3];[4;5];[6;7;8]]=[1;2;3;4;5;6;7;8])

let test () =
  test_somme ();
  test_recherche ();
  test_concatener();;

test()
