package stack

import "container/list"

type Stack struct {
	data *list.List
}

func New() *Stack {
	return &Stack{
		data:list.New(),
	}
}

func (s *Stack)Push(v interface{}) {
	s.data.PushBack(v)
}

func (s *Stack)Pop()interface{} {
	e := s.data.Back()
	s.data.Remove(e)

	return e.Value
}

func (s *Stack)Top() interface{} {
	e := s.data.Back()
	return e.Value
}

func (s *Stack)IsEmpty() bool {
	if s.data.Len() == 0 {
		return true
	}

	return false
}
