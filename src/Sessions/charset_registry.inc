// ISO 2022 charset registry registered by FUN_00801a58 (31 entries;
// tuple = FUN_008019b0(entry, id, name, set96, disabled)).
// Entry layout in the binary: +0 id, +8 name d-ptr, +0x10 set96, +0x11 disabled.
static const struct { int id; const char *name; unsigned char set96, disabled; }
charsetRegistry[] = {
	{  2, "B", 0, 0 },   // #0
	{  3, "0", 0, 0 },   // #1
	{  4, "1", 0, 0 },   // #2
	{  5, "2", 0, 0 },   // #3
	{  6, "%5", 0, 0 },   // #4
	{  7, ">", 0, 0 },   // #5
	{  8, "A", 0, 1 },   // #6
	{  9, "4", 0, 1 },   // #7
	{ 10, "5", 0, 1 },   // #8
	{ 10, "C", 0, 1 },   // #9
	{ 11, "R", 0, 1 },   // #10
	{ 12, "Q", 0, 1 },   // #11
	{ 12, "9", 0, 1 },   // #12
	{ 13, "K", 0, 1 },   // #13
	{ 14, "Y", 0, 1 },   // #14
	{ 15, "E", 0, 1 },   // #15
	{ 15, "6", 0, 1 },   // #16
	{ 15, "`", 0, 1 },   // #17
	{ 16, "%6", 0, 1 },   // #18
	{ 17, "Z", 0, 1 },   // #19
	{ 18, "H", 0, 1 },   // #20
	{ 18, "7", 0, 1 },   // #21
	{ 19, "=", 0, 1 },   // #22
	{ 20, "L", 1, 0 },   // #23
	{ 21, "F", 1, 0 },   // #24
	{ 22, "H", 1, 0 },   // #25
	{ 23, "A", 1, 0 },   // #26
	{ 24, "B", 1, 0 },   // #27
	{ 25, "M", 1, 0 },   // #28
	{  1, "<", 0, 0 },   // #29
	{  1, "<", 1, 0 },   // #30
};
// id -> registry row (FUN_008034f2 slot table; duplicate id 1 -> later wins)
static int charsetRowById(int id) {
	int row = -1;
	for (int i = 0; i < 31; ++i)
		if (charsetRegistry[i].id == id) row = i;
	return row;
}
