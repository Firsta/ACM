{$inline on}
program sequence;

const
  maxn = 500003;

type
  pointer = ^node;
  node = record
    value, sum, maxl, maxr, maxm, size : longint;
    same, rev : boolean;
    pre : pointer;
    ch : array[0..1] of pointer;
  end;

var
  queue, stack : array[1..maxn] of pointer;
  tmp : array[1..maxn] of longint;
  tree : array[1..maxn] of node;
  Null, root : pointer;
  total, top : longint;

function max(a, b : longint) : longint; inline;
  begin
    if a > b then exit(a) else exit(b);
  end;

procedure swap(var a, b : longint); inline;
  var
    t : longint;
  begin
    t := a;
    a := b;
    b := t;
  end;

procedure swap(var a, b : pointer); inline;
  var
    t : pointer;
  begin
    t := a;
    a := b;
    b := t;
  end;

function New_Node(x : longint) : pointer; inline;
  var
    p : pointer;
  begin
    if top = 0 then
      begin
        inc(total);
        p := @tree[total];
      end
    else
      begin
        p := stack[top];
        dec(top);
      end;
    p^.value := x;
    p^.maxl := x;
    p^.maxr := x;
    p^.maxm := x;
    p^.sum := x;
    p^.size := 1;
    p^.ch[0] := Null;
    p^.ch[1] := Null;
    p^.pre := Null;
    p^.same := false;
    p^.rev := false;
    exit(p);
  end;

procedure Make_Same(p : pointer; new_value : longint); inline;
  begin
    if p = Null then exit;
    p^.maxl := p^.size * new_value;
    p^.maxr := p^.size * new_value;
    p^.maxm := p^.size * new_value;
    p^.sum := p^.size * new_value;
    p^.value := new_value;
    if new_value < 0 then
      begin
        p^.maxl := new_value;
        p^.maxr := new_value;
        p^.maxm := new_value;
      end;
    p^.same := true;
  end;

procedure Reverse(p : pointer); inline;
  begin
    if p = Null then exit;
    swap(p^.ch[0], p^.ch[1]);
    swap(p^.maxl, p^.maxr);
    p^.rev := not p^.rev;
  end;

procedure Update(p : pointer); inline;
  begin
    p^.size := p^.ch[0]^.size + p^.ch[1]^.size + 1;
    p^.sum := p^.ch[0]^.sum + p^.ch[1]^.sum + p^.value;
    p^.maxl := max(p^.ch[0]^.maxl, p^.ch[0]^.sum + p^.value + max(p^.ch[1]^.maxl, 0));
    p^.maxr := max(p^.ch[1]^.maxr, p^.ch[1]^.sum + p^.value + max(p^.ch[0]^.maxr, 0));
    p^.maxm := max(p^.ch[0]^.maxm, p^.ch[1]^.maxm);
    p^.maxm := max(p^.maxm, max(p^.ch[0]^.maxr + p^.ch[1]^.maxl, 0) + p^.value);
    p^.maxm := max(p^.maxm, max(p^.ch[0]^.maxr, p^.ch[1]^.maxl) + p^.value);
  end;

procedure Push_Down(p : pointer); inline;
  begin
    if p^.same then
      begin
        Make_Same(p^.ch[0], p^.value);
        Make_Same(p^.ch[1], p^.value);
        p^.same := false;
      end;
    if p^.rev then
      begin
        Reverse(p^.ch[0]);
        Reverse(p^.ch[1]);
        p^.rev := false;
      end;
  end;

procedure Rotate(x : pointer; c : longint); inline;
  var
    y : pointer;
  begin
    y := x^.pre;
    Push_Down(y);
    Push_Down(x);
    y^.ch[1 - c] := x^.ch[c];
    if x^.ch[c] <> Null then x^.ch[c]^.pre := y;
    x^.pre := y^.pre;
    if y^.pre <> Null then
      if y^.pre^.ch[0] = y then
        y^.pre^.ch[0] := x
      else
        y^.pre^.ch[1] := x;
    x^.ch[c] := y;
    y^.pre := x;
    if root = y then root := x;
    Update(y);
  end;

procedure Splay(x, f : pointer); inline;
  var
    y, z : pointer;
  begin
    Push_Down(x);
    while x^.pre <> f do
      if x^.pre^.pre = f then
        if x^.pre^.ch[0] = x then Rotate(x, 1) else Rotate(x, 0)
      else
        begin
          y := x^.pre;
          z := y^.pre;
          if z^.ch[0] = y then
            if y^.ch[0] = x then
              begin
                Rotate(y, 1);
                Rotate(x, 1);
              end
            else
              begin
                Rotate(x, 0);
                Rotate(x, 1);
              end
          else
            if y^.ch[1] = x then
              begin
                Rotate(y, 0);
                Rotate(x, 0);
              end
            else
              begin
                Rotate(x, 1);
                Rotate(x, 0);
              end;
        end;
    Update(x);
  end;

procedure Select(k : longint; f : pointer); inline;
  var
    tmp : longint;
    t : pointer;
  begin
    t := root;
    while true do
      begin
        Push_Down(t);
        tmp := t^.ch[0]^.size;
        if k = tmp + 1 then break;
        if k <= tmp then
          t := t^.ch[0]
        else
          begin
            dec(k, tmp + 1);
            t := t^.ch[1];
          end;
      end;
    Splay(t, f);
  end;

function Make_Tree(head, tail : longint) : pointer; inline;
  var
    mid : longint;
    p : pointer;
  begin
    if head > tail then exit(Null);
    mid := (head + tail) shr 1;
    p := New_Node(tmp[mid]);
    p^.ch[0] := Make_Tree(head, mid-1);
    p^.ch[1] := Make_Tree(mid+1, tail);
    if p^.ch[0] <> Null then p^.ch[0]^.pre := p;
    if p^.ch[1] <> Null then p^.ch[1]^.pre := p;
    Update(p);
    exit(p);
  end;

procedure Ins_Num(pos, tot : longint); inline;
  var
    tmp_root : pointer;
    i : longint;
  begin
    for i := 1 to tot do read(tmp[i]);
    tmp_root := Make_Tree(1, tot);
    Select(pos, Null);
    Select(pos+1, root);
    root^.ch[1]^.ch[0] := tmp_root;
    tmp_root^.pre := root^.ch[1];
    Splay(root^.ch[1], Null);
  end;

procedure Clear(x : pointer); inline;
  var
    head, tail : longint;
    p : pointer;
  begin
    head := 1;
    tail := 1;
    queue[1] := x;
    while head <= tail do
      begin
        p := queue[head];
        if p^.ch[0] <> Null then
          begin
            inc(tail);
            queue[tail] := p^.ch[0];
          end;
        if p^.ch[1] <> Null then
          begin
            inc(tail);
            queue[tail] := p^.ch[1];
          end;
        inc(top);
        stack[top] := p;
        inc(head);
      end;
  end;

var
  n, m, i, pos, tot, c : longint;
  ctrl : string;
  ch : char;

begin
  assign(input, 'sequence.in');
  reset(input);
  assign(output, 'sequence.out');
  rewrite(output);

  total := 0;
  Null := New_Node(-100000);
  Null^.sum := 0;
  Null^.size := 0;
  root := New_Node(-100000);
  root^.sum := 0;
  root^.ch[1] := New_Node(-100000);
  root^.ch[1]^.sum := 0;
  root^.ch[1]^.pre := root;
  Update(root);

  readln(n, m);
  Ins_Num(1, n);
  readln;

  for i := 1 to m do
    begin
      ctrl := '';
      while true do
        begin
          read(ch);
          if ch = ' ' then break;
          ctrl := ctrl + ch;
          if eoln then break;
        end;
      if ctrl = 'INSERT' then
        begin
          read(pos, tot);
          Ins_Num(pos+1, tot);
        end;
      if ctrl = 'DELETE' then
        begin
          read(pos, tot);
          Select(pos, Null);
          Select(pos+tot+1, root);
          Clear(root^.ch[1]^.ch[0]);
          root^.ch[1]^.ch[0] := Null;
          Splay(root^.ch[1], Null);
        end;
      if ctrl = 'REVERSE' then
        begin
          read(pos, tot);
          Select(pos, Null);
          Select(pos+tot+1, root);
          Reverse(root^.ch[1]^.ch[0]);
          Splay(root^.ch[1], Null);
        end;
      if ctrl = 'MAKE-SAME' then
        begin
          read(pos, tot, c);
          Select(pos, Null);
          Select(pos+tot+1, root);
          Make_Same(root^.ch[1]^.ch[0], c);
          Splay(root^.ch[1], Null);
        end;
      if ctrl = 'GET-SUM' then
        begin
          read(pos, tot);
          Select(pos, Null);
          Select(pos+tot+1, root);
          writeln(root^.ch[1]^.ch[0]^.sum);
        end;
      if ctrl = 'MAX-SUM' then
        writeln(root^.maxm);
      readln;
    end;

  close(input);
  close(output);
end.
