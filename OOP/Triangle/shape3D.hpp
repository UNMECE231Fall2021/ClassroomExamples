#ifndef BASE_ABSTRACT_SHAPE3D_HPP
#define BASE_ABSTRACT_SHAPE3D_HPP

class Shape3D {
	protected:
		int _depth;

		float _volume;
		float _surface_area;

		virtual void calc_volume() = 0;
		virtual void calc_surface_area() = 0;
		
	public:
		Shape3D();
		Shape3D(const Shape3D &s);

		virtual ~Shape3D();

		int depth() const;
		float volume() const;
		float surface_area() const;

		virtual void set_depth(int depth);
};

#endif // BASE_ABSTRACT_SHAPE3D_HPP
