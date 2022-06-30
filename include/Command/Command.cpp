void move(int forward_or_backward, position& pos) {
    attr a = pos.heading_attribute[pos.heading_code];
    pos.position_x += (a.XorY ^ Y) * a.op * forward_or_backward;
    pos.position_y += (a.XorY ^ X) * a.op * forward_or_backward;
}
