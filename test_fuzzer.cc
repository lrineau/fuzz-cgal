#include <CGAL/Cartesian.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Gmpq.h>
#include <CGAL/Kernel_checker.h>
#include <CGAL/iterator.h>

using EK = CGAL::Cartesian<CGAL::Gmpq>;
using K = CGAL::Epick;
using Checker = CGAL::Kernel_checker<EK, K>;

bool debug_output = false;

extern "C" int LLVMFuzzerInitialize(int *argc, char ***) {
  std::cerr << "Initialize..\n";
  std::cerr.precision(17);
  std::cout.precision(17);
  if(*argc > 1) debug_output = true;
  return 0;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  constexpr int s = 4 * 3;
  if (size == sizeof(double) * s) {
    if(debug_output)
      std::cout << "Input 3D points (4*3 doubles):\n";
    const double *coords = reinterpret_cast<const double *>(data);
    for (auto d : CGAL::make_range(coords, coords + s)) {
      if (!CGAL::is_finite(d))
        return 0;
      if(debug_output)
        std::cout << "  " << d << '\n';
    }
    if(debug_output) std::cout << std::endl;

    Checker::Point_3 pa{{coords[0], coords[1], coords[2]},
                        {coords[0], coords[1], coords[2]}};
    Checker::Point_3 pb{{coords[3], coords[4], coords[5]},
                        {coords[3], coords[4], coords[5]}};
    Checker::Point_3 pc{{coords[6], coords[7], coords[8]},
                        {coords[6], coords[7], coords[8]}};
    Checker::Point_3 pd{{coords[9], coords[10], coords[11]},
                        {coords[9], coords[10], coords[11]}};
    Checker::Orientation_3()(pa, pb, pc, pd);
  }
  return 0;
}
