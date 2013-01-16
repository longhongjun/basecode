<?php
/**
 * Automatically generated by running "php schema.php simplexml".
 *
 * You may modify the file, but re-running schema.php against this file will
 * standardize the format without losing your schema changes. It does lose
 * any changes that are not part of schema. Use "note" field to comment on
 * schema itself, and "note" fields are not used in any code generation but
 * only staying within this file.
 */
///////////////////////////////////////////////////////////////////////////////
// Preamble: C++ code inserted at beginning of ext_{name}.h

DefinePreamble(<<<CPP
#include <runtime/ext/ext_simplexml_include.h>
CPP
);

///////////////////////////////////////////////////////////////////////////////
// Constants
//
// array (
//   'name' => name of the constant
//   'type' => type of the constant
//   'note' => additional note about this constant's schema
// )


///////////////////////////////////////////////////////////////////////////////
// Functions
//
// array (
//   'name'   => name of the function
//   'desc'   => description of the function's purpose
//   'flags'  => attributes of the function, see base.php for possible values
//   'opt'    => optimization callback function's name for compiler
//   'note'   => additional note about this function's schema
//   'return' =>
//      array (
//        'type'  => return type, use Reference for ref return
//        'desc'  => description of the return value
//      )
//   'args'   => arguments
//      array (
//        'name'  => name of the argument
//        'type'  => type of the argument, use Reference for output parameter
//        'value' => default value of the argument
//        'desc'  => description of the argument
//      )
// )

DefineFunction(
  array(
    'name'   => "simplexml_load_string",
    'desc'   => "Takes a well-formed XML string and returns it as an object.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
      'desc'   => "Returns an object of class SimpleXMLElement with properties containing the data held within the xml document. On errors, it will return FALSE.",
    ),
    'args'   => array(
      array(
        'name'   => "data",
        'type'   => String,
        'desc'   => "A well-formed XML string",
      ),
      array(
        'name'   => "class_name",
        'type'   => String,
        'value'  => "\"SimpleXMLElement\"",
        'desc'   => "You may use this optional parameter so that simplexml_load_string() will return an object of the specified class. That class should extend the SimpleXMLElement class.",
      ),
      array(
        'name'   => "options",
        'type'   => Int64,
        'value'  => "0",
        'desc'   => "Since PHP 5.1.0 and Libxml 2.6.0, you may also use the options parameter to specify additional Libxml parameters.",
      ),
      array(
        'name'   => "ns",
        'type'   => String,
        'value'  => "\"\"",
      ),
      array(
        'name'   => "is_prefix",
        'type'   => Boolean,
        'value'  => "false",
      ),
    ),
    'taint_observer' => array(
      'set_mask'   => "TAINT_BIT_NONE",
      'clear_mask' => "TAINT_BIT_NONE",
    ),
  ));

DefineFunction(
  array(
    'name'   => "simplexml_load_file",
    'desc'   => "Convert the well-formed XML document in the given file to an object.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
      'desc'   => "Returns an object of class SimpleXMLElement with properties containing the data held within the XML document. On errors, it will return FALSE.",
    ),
    'args'   => array(
      array(
        'name'   => "filename",
        'type'   => String,
        'desc'   => "Path to the XML file\n\nLibxml 2 unescapes the URI, so if you want to pass e.g. b&c as the URI parameter a, you have to call simplexml_load_file(rawurlencode('http://example.com/?a=' . urlencode('b&c'))). Since PHP 5.1.0 you don't need to do this because PHP will do it for you.",
      ),
      array(
        'name'   => "class_name",
        'type'   => String,
        'value'  => "\"SimpleXMLElement\"",
        'desc'   => "You may use this optional parameter so that simplexml_load_file() will return an object of the specified class. That class should extend the SimpleXMLElement class.",
      ),
      array(
        'name'   => "options",
        'type'   => Int64,
        'value'  => "0",
        'desc'   => "Since PHP 5.1.0 and Libxml 2.6.0, you may also use the options parameter to specify additional Libxml parameters.",
      ),
      array(
        'name'   => "ns",
        'type'   => String,
        'value'  => "\"\"",
      ),
      array(
        'name'   => "is_prefix",
        'type'   => Boolean,
        'value'  => "false",
      ),
    ),
    'taint_observer' => false,
  ));

DefineFunction(
  array(
    'name'   => "libxml_get_errors",
    'desc'   => "Retrieve array of errors.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
      'desc'   => "Returns an array with LibXMLError objects if there are any errors in the buffer, or an empty array otherwise.",
    ),
    'taint_observer' => false,
  ));

DefineFunction(
  array(
    'name'   => "libxml_get_last_error",
    'desc'   => "Retrieve last error from libxml.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
      'desc'   => "Returns a LibXMLError object if there is any error in the buffer, FALSE otherwise.",
    ),
    'taint_observer' => false,
  ));

DefineFunction(
  array(
    'name'   => "libxml_clear_errors",
    'desc'   => "libxml_clear_errors() clears the libxml error buffer.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => null,
      'desc'   => "No value is returned.",
    ),
    'taint_observer' => false,
  ));

DefineFunction(
  array(
    'name'   => "libxml_use_internal_errors",
    'desc'   => "libxml_use_internal_errors() allows you to disable standard libxml errors and enable user error handling.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Boolean,
      'desc'   => "This function returns the previous value of use_errors.",
    ),
    'args'   => array(
      array(
        'name'   => "use_errors",
        'type'   => Variant,
        'value'  => "null_variant",
        'desc'   => "Whether to enable user error handling.",
      ),
    ),
    'taint_observer' => false,
  ));

DefineFunction(
  array(
    'name'   => "libxml_set_streams_context",
    'desc'   => "Sets the streams context for the next libxml document load or write.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => null,
      'desc'   => "No value is returned.",
    ),
    'args'   => array(
      array(
        'name'   => "streams_context",
        'type'   => Resource,
        'desc'   => "The stream context resource (created with stream_context_create())",
      ),
    ),
    'taint_observer' => false,
  ));

DefineFunction(
  array(
    'name'   => "libxml_disable_entity_loader",
    'desc'   => "Disable/enable the ability to load external entities.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Boolean,
      'desc'   => "Returns the previous value.",
    ),
    'args'   => array(
      array(
        'name'   => "disable",
        'type'   => Boolean,
        'value'  => "true",
        'desc'   => "Disable (TRUE) or enable (FALSE) libxml extensions (such as DOM, XMLWriter and XMLReader) to load external entities.",
      ),
    ),
    'taint_observer' => false,
  ));


///////////////////////////////////////////////////////////////////////////////
// Classes
//
// BeginClass
// array (
//   'name'   => name of the class
//   'desc'   => description of the class's purpose
//   'flags'  => attributes of the class, see base.php for possible values
//   'note'   => additional note about this class's schema
//   'parent' => parent class name, if any
//   'ifaces' => array of interfaces tihs class implements
//   'bases'  => extra internal and special base classes this class requires
//   'footer' => extra C++ inserted at end of class declaration
// )
//
// DefineConstant(..)
// DefineConstant(..)
// ...
// DefineFunction(..)
// DefineFunction(..)
// ...
// DefineProperty
// DefineProperty
//
// array (
//   'name'  => name of the property
//   'type'  => type of the property
//   'flags' => attributes of the property
//   'desc'  => description of the property
//   'note'  => additional note about this property's schema
// )
//
// EndClass()

///////////////////////////////////////////////////////////////////////////////

BeginClass(
  array(
    'name'   => "SimpleXMLElement",
    'bases'  => array('Sweepable'),
    'ifaces' => array('ArrayAccess', 'IteratorAggregate', 'Countable'),
    'desc'   => "Represents an element in an XML document.",
    'flags'  =>  HasDocComment | NoDefaultSweep,
    'footer' => <<<EOT

 public:
  Object m_doc;
  xmlNodePtr m_node;
  Variant m_children;
  Variant m_attributes;
  bool m_is_text;
  bool m_free_text;
  bool m_is_attribute;
  bool m_is_children;
  bool m_is_property;
  virtual bool o_toBoolean() const;
  virtual int64 o_toInt64() const;
  virtual double o_toDouble() const;
  virtual Array o_toArray() const;
  virtual Variant *___lval(Variant v_name);
 private:
  xmlXPathContextPtr m_xpath;
EOT
,
  ));

DefineFunction(
  array(
    'name'   => "__construct",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => null,
    ),
    'args'   => array(
      array(
        'name'   => "data",
        'type'   => String,
      ),
      array(
        'name'   => "options",
        'type'   => Int64,
        'value'  => "0",
      ),
      array(
        'name'   => "data_is_url",
        'type'   => Boolean,
        'value'  => "false",
      ),
      array(
        'name'   => "ns",
        'type'   => String,
        'value'  => "\"\"",
      ),
      array(
        'name'   => "is_prefix",
        'type'   => Boolean,
        'value'  => "false",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "offsetExists",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Boolean,
    ),
    'args'   => array(
      array(
        'name'   => "index",
        'type'   => Variant,
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "offsetGet",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
    'args'   => array(
      array(
        'name'   => "index",
        'type'   => Variant,
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "offsetSet",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => null,
    ),
    'args'   => array(
      array(
        'name'   => "index",
        'type'   => Variant,
      ),
      array(
        'name'   => "newvalue",
        'type'   => Variant,
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "offsetUnset",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => null,
    ),
    'args'   => array(
      array(
        'name'   => "index",
        'type'   => Variant,
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "getIterator",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
  ));

DefineFunction(
  array(
    'name'   => "count",
    'desc'   => "This method counts the number of children of an element.",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Int64,
      'desc'   => "Returns the number of elements of an element.",
    ),
  ));

DefineFunction(
  array(
    'name'   => "xpath",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
      'desc'   => "Returns an array of SimpleXMLElement objects or FALSE in case of an error.",
    ),
    'args'   => array(
      array(
        'name'   => "path",
        'type'   => String,
        'desc'   => "An XPath path",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "registerXPathNamespace",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Boolean,
    ),
    'args'   => array(
      array(
        'name'   => "prefix",
        'type'   => String,
      ),
      array(
        'name'   => "ns",
        'type'   => String,
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "asXML",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
    'args'   => array(
      array(
        'name'   => "filename",
        'type'   => String,
        'value'  => "\"\"",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "getNamespaces",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => StringMap,
    ),
    'args'   => array(
      array(
        'name'   => "recursive",
        'type'   => Boolean,
        'value'  => "false",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "getDocNamespaces",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => StringMap,
    ),
    'args'   => array(
      array(
        'name'   => "recursive",
        'type'   => Boolean,
        'value'  => "false",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "children",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Object,
      'desc'   => "Returns a SimpleXMLElement element, whether the node has children or not.",
    ),
    'args'   => array(
      array(
        'name'   => "ns",
        'type'   => String,
        'value'  => "\"\"",
        'desc'   => "An XML namespace.",
      ),
      array(
        'name'   => "is_prefix",
        'type'   => Boolean,
        'value'  => "false",
        'desc'   => "If is_prefix is TRUE, ns will be regarded as a prefix. If FALSE, ns will be regarded as a namespace URL.",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "getName",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => String,
    ),
  ));

DefineFunction(
  array(
    'name'   => "attributes",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Object,
    ),
    'args'   => array(
      array(
        'name'   => "ns",
        'type'   => String,
        'value'  => "\"\"",
        'desc'   => "An optional namespace for the retrieved attributes",
      ),
      array(
        'name'   => "is_prefix",
        'type'   => Boolean,
        'value'  => "false",
        'desc'   => "Default to FALSE",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "addChild",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
    'args'   => array(
      array(
        'name'   => "qname",
        'type'   => String,
      ),
      array(
        'name'   => "value",
        'type'   => String,
        'value'  => "null_string",
      ),
      array(
        'name'   => "ns",
        'type'   => String,
        'value'  => "null_string",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "addAttribute",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => null,
    ),
    'args'   => array(
      array(
        'name'   => "qname",
        'type'   => String,
      ),
      array(
        'name'   => "value",
        'type'   => String,
        'value'  => "null_string",
      ),
      array(
        'name'   => "ns",
        'type'   => String,
        'value'  => "null_string",
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "__toString",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => String,
    ),
  ));

DefineFunction(
  array(
    'name'   => "__get",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
    'args'   => array(
      array(
        'name'   => "name",
        'type'   => Variant,
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "__set",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
    'args'   => array(
      array(
        'name'   => "name",
        'type'   => Variant,
      ),
      array(
        'name'   => "value",
        'type'   => Variant,
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "__isset",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Boolean,
    ),
    'args'   => array(
      array(
        'name'   => "name",
        'type'   => Variant,
      ),
    ),
  ));

DefineFunction(
  array(
    'name'   => "__unset",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
    'args'   => array(
      array(
        'name'   => "name",
        'type'   => Variant,
      ),
    ),
  ));

EndClass(
);

///////////////////////////////////////////////////////////////////////////////

BeginClass(
  array(
    'name'   => "LibXMLError",
    'desc'   => "Contains various information about errors thrown by libxml. The error codes are described within the official � xmlError API documentation.",
    'flags'  =>  HasDocComment,
  ));

DefineFunction(
  array(
    'name'   => "__construct",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => null,
    ),
  ));

EndClass(
);

///////////////////////////////////////////////////////////////////////////////

BeginClass(
  array(
    'name'   => "SimpleXMLElementIterator",
    'ifaces' => array('Iterator'),
    'bases'  => array('Sweepable'),
    'desc'   => "",
    'flags'  =>  HasDocComment | NoDefaultSweep,
    'footer' => <<<EOT

public:
  void reset_iterator(c_SimpleXMLElement *parent);

  c_SimpleXMLElement *m_parent;
  ArrayIter *m_iter1;
  ArrayIter *m_iter2;
  Object     m_temp;
EOT
,
  ));

DefineFunction(
  array(
    'name'   => "__construct",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => null,
    ),
  ));

DefineFunction(
  array(
    'name'   => "current",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
  ));

DefineFunction(
  array(
    'name'   => "key",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
  ));

DefineFunction(
  array(
    'name'   => "next",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
  ));

DefineFunction(
  array(
    'name'   => "rewind",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
  ));

DefineFunction(
  array(
    'name'   => "valid",
    'flags'  =>  HasDocComment,
    'return' => array(
      'type'   => Variant,
    ),
  ));

EndClass(
);

