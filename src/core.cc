#include <boost/python.hpp>
#include <boost/optional/optional.hpp>

#include <nix.hpp>
#include <transmorgify.hpp>
#include <accessors.hpp>

#include <PyEntity.hpp>

using namespace boost::python;
using namespace nix;
using namespace base;
using namespace nixpy;

static void
nix_data_array_label_setter ( DataArray &da, const boost::optional<std::string> &lbl ) {
    if ( lbl == boost::none ) {
        da.label ( boost::none );
    } else {
        da.label ( *lbl );
    }
}


BOOST_PYTHON_MODULE(core)
{
    PyFile::do_export();

    PySection::do_export();
    PyProperty::do_export();
    PyValue::do_export();

    PyBlock::do_export();
    PySource::do_export();

    PyEntityWithSources<IDataArray>::do_export("DataArray");
    class_<DataArray, bases<EntityWithSources<IDataArray>>>("DataArray")
        .add_property("label",
                      OPT_GETTER(std::string, DataArray, label),
                      &nix_data_array_label_setter)
        .def("has_data", &DataArray::hasData)
        ;


    to_python_converter<std::vector<DataArray>, vector_transmogrify<DataArray>>();
    vector_transmogrify<DataArray>::register_from_python();
    to_python_converter<boost::optional<DataArray>, option_transmogrify<DataArray>>();


    // TODO enum class DataType

    class_<Dimension>("Dimension");

    class_<SampledDimension>("SampledDimension");

    class_<RangeDimension>("RangeDimension");

    class_<SetDimension>("SetDimension");

    PyEntityWithSources<ISimpleTag>::do_export("SimpleTag");
    class_<SimpleTag, bases<EntityWithSources<ISimpleTag>>>("SimpleTag");
    to_python_converter<std::vector<SimpleTag>, vector_transmogrify<SimpleTag>>();
    to_python_converter<boost::optional<SimpleTag>, option_transmogrify<SimpleTag>>();

    PyEntityWithSources<IDataTag>::do_export("DataTag");
    class_<DataTag, bases<EntityWithSources<IDataTag>>>("DataTag");
    to_python_converter<std::vector<DataTag>, vector_transmogrify<DataTag>>();
    to_python_converter<boost::optional<DataTag>, option_transmogrify<DataTag>>();

    class_<Feature>("Feature");

    // TODO enum class LinkType

    to_python_converter<boost::optional<std::string>, option_transmogrify<std::string>>();
    option_transmogrify<std::string>::register_from_python();
}
