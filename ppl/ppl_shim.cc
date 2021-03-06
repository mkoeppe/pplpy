#include "ppl_shim.hh"

// /************************************************************/
Generator* new_line(const Linear_Expression& e)
{
  return new Generator(Generator::line(e));
}

Generator* new_ray(const Linear_Expression& e)
{
  return new Generator(Generator::ray(e));
}

Generator* new_point(const Linear_Expression& e, Coefficient d)
{
  return new Generator(Generator::point(e, d));
}

Generator* new_closure_point(const Linear_Expression& e, Coefficient d)
{
  return new Generator(Generator::closure_point(e, d));
}


/************************************************************/
Poly_Gen_Relation* new_relation_with(const Polyhedron &p, const Generator &g)
{
  return new Poly_Gen_Relation(p.relation_with(g));
}

Poly_Con_Relation* new_relation_with(const Polyhedron &p, const Constraint &c)
{
  return new Poly_Con_Relation(p.relation_with(c));
}


/************************************************************/
typedef Generator_System::const_iterator* gs_iterator_ptr;

gs_iterator_ptr init_gs_iterator(const Generator_System &gs)
{
  return new Generator_System::const_iterator(gs.begin());
}

Generator next_gs_iterator(gs_iterator_ptr gsi_ptr)
{
  return *(*gsi_ptr)++;
}

bool is_end_gs_iterator(const Generator_System &gs, gs_iterator_ptr gsi_ptr)
{
  return (*gsi_ptr) == gs.end();
}

void delete_gs_iterator(gs_iterator_ptr gsi_ptr)
{
  delete gsi_ptr;
}


/************************************************************/
typedef Constraint_System::const_iterator* cs_iterator_ptr;

cs_iterator_ptr init_cs_iterator(const Constraint_System &cs)
{
  return new Constraint_System::const_iterator(cs.begin());
}

Constraint next_cs_iterator(cs_iterator_ptr csi_ptr)
{
  return *(*csi_ptr)++;
}

bool is_end_cs_iterator(const Constraint_System &cs, cs_iterator_ptr csi_ptr)
{
  return (*csi_ptr) == cs.end();
}

void delete_cs_iterator(cs_iterator_ptr csi_ptr)
{
  delete csi_ptr;
}


/************************************************************/
typedef MIP_Problem::const_iterator* mip_cs_iterator_ptr;

Generator* new_MIP_optimizing_point(const MIP_Problem& pb)
{
  return new Generator(pb.optimizing_point());
}

mip_cs_iterator_ptr init_mip_cs_iterator(const MIP_Problem& pb)
{
  return new MIP_Problem::const_iterator(pb.constraints_begin());
}

Constraint next_mip_cs_iterator(mip_cs_iterator_ptr mip_csi_ptr)
{
  return *(*mip_csi_ptr)++;
}

bool is_end_mip_cs_iterator(const MIP_Problem &pb, mip_cs_iterator_ptr mip_csi_ptr)
{
  return (*mip_csi_ptr) == pb.constraints_end();
}

void delete_mip_cs_iterator(mip_cs_iterator_ptr mip_csi_ptr)
{
  delete mip_csi_ptr;
}

Constraint_System* mip_constraints(const MIP_Problem &pb)
{
	Constraint_System *cs = new Constraint_System();
	for(MIP_Problem::const_iterator it = pb.constraints_begin();
		it != pb.constraints_end();
		++it)
		cs->insert(*it);
	return cs;
}
