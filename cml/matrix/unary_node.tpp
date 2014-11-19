/* -*- C++ -*- ------------------------------------------------------------
 @@COPYRIGHT@@
 *-----------------------------------------------------------------------*/
/** @file
 */

#ifndef __CML_MATRIX_UNARY_NODE_TPP
#error "matrix/unary_node.tpp not included correctly"
#endif

namespace cml {

/* matrix_unary_node 'structors: */

template<class Sub, class Op>
matrix_unary_node<Sub,Op>::matrix_unary_node(Sub sub)
: m_sub(std::move(sub))
{
}

template<class Sub, class Op>
matrix_unary_node<Sub,Op>::matrix_unary_node(node_type&& other)
: m_sub(std::move(other.m_sub))
{
}



/* Public methods: */

template<class Sub, class Op> int
matrix_unary_node<Sub,Op>::rows() const
{
  return this->m_sub.rows();
}

template<class Sub, class Op> int
matrix_unary_node<Sub,Op>::cols() const
{
  return this->m_sub.cols();
}

template<class Sub, class Op> auto
matrix_unary_node<Sub,Op>::get(int i, int j) const -> immutable_value
{
  return Op().apply(this->m_sub.get(i,j));
}

} // namespace cml

// -------------------------------------------------------------------------
// vim:ft=cpp:sw=2
