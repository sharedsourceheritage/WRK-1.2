//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET Framework SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------

#using <mscorlib.dll>
#using <System.Runtime.Serialization.Formatters.Soap.dll>

using namespace System;
using namespace System::IO;
using namespace System::Diagnostics;
using namespace System::Reflection;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::Runtime::Serialization::Formatters::Soap;
using namespace System::Security::Permissions;
using namespace System::Text;
using namespace System::Collections;

// TreeNode class
[Serializable] public ref class TreeNode : public ISerializable {
private:
	Object^ value;
	ArrayList^ children;

private:
	TreeNode( SerializationInfo^ info, StreamingContext c ) {
		value = info->GetValue( "value", Object::typeid );
		children = gcnew ArrayList;
		Object^ o;

		for( int i = 1; i < info->MemberCount; i++ ) {
			o = info->GetValue( i.ToString(), Object::typeid );
			children->Add(o);
        }
    }

	void PrintTree( TextWriter^ output, int offset ) {
		StringBuilder^ sb1 = gcnew StringBuilder;
		StringBuilder^ sb2 = gcnew StringBuilder;
		for( int i = 0; i < offset-1; i++ ) {
			sb1->Append(" ");
			sb1->Append("|");
			sb2->Append(" ");
			sb2->Append("|");
		}
		if( offset >=1 ) {
			sb1->Append(" ");
			sb1->Append("+-");
			sb2->Append(" ");
			sb2->Append("|");
		}
		output->WriteLine( "{0}", sb2 );
		output->WriteLine( "{0}{1}", sb1, value );
		for( int i = 0; i < children->Count; i++ ) {
			try {
				safe_cast<TreeNode^>( children->default[i] )->PrintTree( output, offset+1 );
			}
			catch( InvalidCastException^ e ) {
				e = gcnew InvalidCastException( "Error: Cast failed in TreeNode::PrintTree." );
				throw e;
			}
		}
	}

public:
	TreeNode( Object^ val ) {
		if( val == nullptr ) throw gcnew Exception( "val must not be null" );
		value = val;
		children = gcnew ArrayList();
	}

	property Object^ Value {
		Object^ get()
		{
			return value;
			}
	}

    void AddChild( TreeNode^ child ) {
        if( !children->Contains(child) )
            children->Add(child);
    }

	// Override ISerializable::GetObjectData
	[SecurityPermissionAttribute(SecurityAction::Demand, SerializationFormatter=true)]
	virtual void GetObjectData( SerializationInfo^ info, StreamingContext context ) {
        if( value == nullptr ) info->AddValue( "value", "NULL" );
		else info->AddValue( "value", String::Concat( value->ToString(), "(SAVED)" ) );

		Object^ o;
		for( int n = 0; n < children->Count; n++ ) {
			o = children->default[n];
			if( o == nullptr ) continue;
            info->AddValue( (n+1).ToString(), o);
        }
    }

    TreeNode^ Find( Object^ val ) {
		if( val == nullptr ) throw gcnew Exception( "val must not be null" );
		if( value->Equals(val) ) return this;

		TreeNode^ w;
		for( int n = 0; n < children->Count; n++ ) {
			try {
				w = safe_cast<TreeNode^>( children->default[n] )->Find( val );
			}
			catch( InvalidCastException^ e ) {
				e = gcnew InvalidCastException( "Error: Cast failed." );
				throw e;
			}

			if( w != nullptr ) return w;
		}
		return nullptr;
	}

	// Override Object::Equals()
	virtual bool Equals( Object^ obj ) override {
		if( obj->GetType() != TreeNode::typeid ) return false;
		TreeNode^ t = dynamic_cast<TreeNode^>( obj );
		return( t->value->Equals( this->value ) );
    }

	// Override Object::ToString()
    virtual String^ ToString() override {
        return value->ToString();
    }

	void PrintTree( TextWriter^ output ) {
		PrintTree( output, 0 );
	}

};

// main helper function
void FillTree( TreeNode^ node ) {
	array<Type^>^ types = Object::typeid ->Module->Assembly->GetTypes();
	node->AddChild( gcnew TreeNode( Object::typeid->FullName ) );

	for( int i = 0; i < types->Length; i++ ) {
		if( types[i]->BaseType == nullptr ) continue;
		if( !types[i]->IsPublic ) continue;
		TreeNode^ n = node->Find( types[i]->BaseType->FullName );
		if( n != nullptr ) n->AddChild( gcnew TreeNode( types[i] ) );
	}
}

int main( void ) {

	Console::WriteLine( "Create object graph" );
	TreeNode^ node = gcnew TreeNode( "" );
	FillTree( node );
	try {
		node->PrintTree( Console::Out );
	}
	catch( InvalidCastException^ e ) {
		Console::WriteLine( e->Message );
		return -1;
	}

	Console::Write( "Serializing object graph to disk.." );
	Stream^ s = File::Open( "foo.xml", FileMode::Create, FileAccess::Write );
	SoapFormatter^ b = gcnew SoapFormatter;
	b->Serialize( s, node );
	s->Close();
	Console::WriteLine( "Complete." );

	Console::Write( "Deserializing object graph from disk.." );
	Stream^ r = File::Open( "foo.xml", FileMode::Open, FileAccess::Read );
	SoapFormatter^ c = gcnew SoapFormatter;

	TreeNode^ n;
	try {
		n = safe_cast<TreeNode^>( c->Deserialize(r) );
	}
	catch( InvalidCastException^ e ) {
		Console::WriteLine( e->Message );
		return -1;
	}

	Console::WriteLine( "Complete." );
	r->Close();

	try {
		n->PrintTree( Console::Out );
	}
	catch( InvalidCastException^ e ) {
		Console::WriteLine( e->Message );
		return -1;
	}

	Console::WriteLine( "\r\nPress Return to exit." );
	Console::Read();

    return 0;
}
