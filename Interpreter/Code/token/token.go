package token

//Distinguish between different types of token
type TokenType string

type Token struct {
	Type TokenType
	Literal string
}

const (

	//Special
	ILLEGAL = "ILLEGAL"
	EOF = "EOF"

	//Identifiers + literals 
	IDENT = "IDENT" // add, foobar, x, y
	INT = "INT"

	//Operators
	ASSIGN = "="
	PLUS = "+"

	//Delimiters
	COMMA = ","
	SEMICOLON = ";"

	LPAREN = "("
	RPAREN = ")"
	LBRACE = "{"
	RBRACE = "}"

	//Keywords
	FUNCTION = "FUNCTION"
	LET = "LET"
)